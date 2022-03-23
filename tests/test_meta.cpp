#include <gtest/gtest.h>
#include "setOptions.hpp"
#include "metaAnalysis.hpp"
#include <string>
#include <vector>
#include "meta_stepwise_reader.h"
using namespace std;

/**
 * "Very small" meaning it requires long double precision or handling in log-scale.
 */
TEST(MetaTest, StepwiseConditionalWithVerySmallPvalue) {
  global_opts::reset();
  global_opts::set_global_region("");
  global_opts::set_exp_weight(0);
  global_opts::set_max_signals(10);
  global_opts::process_global_opts(
    "data/test_output.pval0",           // prefix
    false,        // use low mem
    2,            // rsq_buddy
    0.8,          // rsq_prune
    0.05,         // p-value threshold
    1000000,      // window size
    {},           // target genes
    '0',          // ivw method
    false,        // use_ds (dosage)
    false,        // trim gene ids
    0.05,         // stepwise_backward_thresh
    true,         // t_hom
    false,        // t_het
    true,         // t_acat
    true,          // stepwise_marginal_thresh
    true           // write out log p-values
  );

  vector<string> meta_prefixes = {"data/pval0"};
  string region = "";
  cis_meta_data meta_dt(meta_prefixes, region);
  meta_dt.conditional_analysis();
  auto reader_truth = StepwiseReader("data/pval0.cis_meta.stepwise.tsv");
  auto reader_test = StepwiseReader("data/test_output.pval0.cis_meta.stepwise.tsv");
  ASSERT_TRUE(reader_truth == reader_test);
}

/**
 * Test the conditional_het() function with a very significant p-value (beyond double precision)
 */
TEST(MetaTest, StepwiseHetConditionalWithVerySmallPvalue) {
  global_opts::reset();
  global_opts::set_global_region("");
  global_opts::set_exp_weight(0);
  global_opts::set_max_signals(10);
  global_opts::process_global_opts(
    "data/test_output.pval0",           // prefix
    false,        // use low mem
    2,            // rsq_buddy
    0.8,          // rsq_prune
    0.05,         // p-value threshold
    1000000,      // window size
    {},           // target genes
    '0',          // ivw method
    false,        // use_ds (dosage)
    false,        // trim gene ids
    0.05,         // stepwise_backward_thresh
    true,         // t_hom
    false,        // t_het
    true,         // t_acat
    true,          // stepwise_marginal_thresh
    true           // write out log p-values
  );

  vector<string> meta_prefixes = {"data/pval0"};
  string region = "";
  cis_meta_data meta_dt(meta_prefixes, region);
  meta_dt.conditional_analysis_het();
  auto reader_truth = StepwiseReader("data/pval0.cis_meta.stepwise_het.tsv");
  auto reader_test = StepwiseReader("data/test_output.pval0.cis_meta.stepwise_het.tsv");
  ASSERT_TRUE(reader_truth == reader_test);
}

/**
 * This test verifies that stepwise conditional analysis works correctly with simple input data (no wild p-values.)
 */
TEST(MetaTest, StepwiseConditionalRegressionTest) {
  global_opts::reset();
  global_opts::set_global_region("");
  global_opts::set_exp_weight(0);
  global_opts::set_max_signals(10);
  global_opts::process_global_opts(
    "data/test_output.simple_pvalue",           // prefix
    false,        // use low mem
    2,            // rsq_buddy
    0.8,          // rsq_prune
    0.05,         // p-value threshold
    1000000,      // window size
    {},           // target genes
    '0',          // ivw method
    false,        // use_ds (dosage)
    false,        // trim gene ids
    0.05,         // stepwise_backward_thresh
    true,         // t_hom
    false,        // t_het
    true,         // t_acat
    true,         // stepwise_marginal_thresh
    false         // write out log p-values
  );

  vector<string> meta_prefixes = {"data/simple_pvalue"};
  string region = "";
  cis_meta_data meta_dt(meta_prefixes, region);
  meta_dt.conditional_analysis();

  // This is generated from latest stable version of APEX, commit 63b605e00766141693a69eee6d630ad8ec3b9de0
  auto reader_truth = StepwiseReader("data/simple_pvalue.cis_meta.stepwise.tsv");

  // This is the file generated by the test case
  auto reader_test = StepwiseReader("data/test_output.simple_pvalue.cis_meta.stepwise.tsv");
  ASSERT_TRUE(reader_truth == reader_test);
}

TEST(MetaTest, StepwiseConditionalHetRegressionTest) {
  global_opts::reset();
  global_opts::set_global_region("");
  global_opts::set_exp_weight(0);
  global_opts::set_max_signals(10);
  global_opts::process_global_opts(
    "data/test_output.simple_pvalue",           // prefix
    false,        // use low mem
    2,            // rsq_buddy
    0.8,          // rsq_prune
    0.05,         // p-value threshold
    1000000,      // window size
    {},           // target genes
    '0',          // ivw method
    false,        // use_ds (dosage)
    false,        // trim gene ids
    0.05,         // stepwise_backward_thresh
    true,         // t_hom
    false,        // t_het
    true,         // t_acat
    true,         // stepwise_marginal_thresh
    false         // write out log p-values
  );

  vector<string> meta_prefixes = {"data/simple_pvalue"};
  string region = "";
  cis_meta_data meta_dt(meta_prefixes, region);
  meta_dt.conditional_analysis_het();

  // This is generated from latest stable version of APEX, commit 63b605e00766141693a69eee6d630ad8ec3b9de0
  auto reader_truth = StepwiseReader("data/simple_pvalue.cis_meta.stepwise_het.tsv");

  // This is the file generated by the test case
  auto reader_test = StepwiseReader("data/test_output.simple_pvalue.cis_meta.stepwise_het.tsv");
  ASSERT_TRUE(reader_truth == reader_test);
}