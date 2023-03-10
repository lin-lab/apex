/*  
    Copyright (C) 2020 
    Author: Corbin Quick <qcorbin@hsph.harvard.edu>

    This file is a part of APEX.

    APEX is distributed "AS IS" in the hope that it will be 
    useful, but WITHOUT ANY WARRANTY; without even the implied 
    warranty of MERCHANTABILITY, NON-INFRINGEMENT, or FITNESS 
    FOR A PARTICULAR PURPOSE.

    The above copyright notice and disclaimer of warranty must 
    be included in all copies or substantial portions of APEX.
*/


#ifndef TRANSMAPPING_HPP
#define TRANSMAPPING_HPP

#include "setOptions.hpp"
#include "readBED.hpp"
#include "setRegions.hpp"
#include "readTable.hpp"
#include "genotypeData.hpp"
#include "htsWrappers.hpp"
#include "fitUtils.hpp"
#include "fitModels.hpp"
#include "miscUtils.hpp"
#include "mathStats.hpp"

#include "apexLMM.hpp"
#include "cisMapping.hpp"

// static std::vector<Eigen::MatrixXd> Z0(0);

void run_trans_QTL_analysis(bcf_srs_t*& sr, bcf_hdr_t*& hdr, genotype_data& g_data, table& c_data, bed_data& e_data, const bool& rknorm_y, const bool& rknorm_r, const bool& make_sumstat, const bool& make_long, const int& chunk_size, const std::string& cis_fp = "", const std::string& cis_fp_region = "" );

void run_trans_QTL_analysis_LMM(bcf_srs_t*& sr, bcf_hdr_t*& hdr, genotype_data& g_data, table& c_data, bed_data& e_data, Eigen::SparseMatrix<double>& L, Eigen::VectorXd& GRM_lambda, const bool& rknorm_y, const bool& rknorm_r, const bool& make_sumstat, const bool& make_long, const int& chunk_size, const std::string& theta_path = "", const std::string& anchor_path = "");


void parse_cis_signal_data(const std::string& fn, const std::string& region, Eigen::MatrixXd& X, std::vector<std::string>& samples, std::vector<std::string>& genes);


#endif

