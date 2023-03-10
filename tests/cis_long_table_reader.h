#ifndef APEX_CIS_LONG_TABLE_READER_H
#define APEX_CIS_LONG_TABLE_READER_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include <fstream>
#include <string>
#include <iostream>
#include <regex>
#include <optional>
#include "reader_util.h"
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/filter/gzip.hpp>

struct CisLongGeneRecord {
  std::string chrom;
  uint64_t pos;
  std::string ref;
  std::string alt;
  std::string gene;
  long double beta;
  long double se;
  long double pval;
};

/**
 * Class to read stepwise conditional analysis results as generated by apex meta --stepwise.
 */
class CisLongTableReader {
protected:
  std::vector<std::shared_ptr<CisLongGeneRecord>> records;
  std::map<std::string, std::shared_ptr<CisLongGeneRecord>> index;
public:
  CisLongTableReader(const std::string &file);
  void load(const std::string &file);
  std::shared_ptr<CisLongGeneRecord> get_record(const std::string &i);

  bool operator==(const CisLongTableReader& other);
};

#endif //APEX_CIS_LONG_TABLE_READER_H