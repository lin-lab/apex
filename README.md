
# YAX: *Y*et *a*nother *x*QTL toolkit
YAX is a comprehensive software toolkit for analysis of molecular quantitative trait loci (xQTLs) including eQTLs (mRNA expression) and  mQTL (methylation). To install YAX, [please see documentation below](##installation). Key features of YAX include

**Fast, scalable linear mixed model for xQTL mapping**
 - Highly optimized linear mixed model (LMM) framework to account for cryptic or familial relatedness in cis and trans xQTL analysis. 
 - Optimized ordinary least squares (OLS) framework for cis and trans xQTL analysis with no related individuals.

**Multiple-variant and omnibus xQTL analysis**
 - Fast, rigorous analytic p-values for cis-region omnibus tests. 
 - Variable selection and conditional analysis procedures to identify multiple association signals for a single molecular trait.
 
**Flexible multiple-variant xQTL meta-analysis framework** 
 - Highly condensed storage formats for xQTL summary statistics, including study-specific LD information. 
 - Single and multiple-variant xQTL meta-analysis procedures.
 - R interface for joint and conditional analysis, Bayesian finemapping, and aggregation tests across 1 or more xQTL studies while protecting genetic privacy.
 
## Analysis modes
 - [**cis-xQTL analysis.**](https://github.com/corbinq/yax/blob/master/doc/mode_cis.md) `./yax cis {options}`
	 - Analyze xQTL associations within a genomic window of each molecular trait.  For example, analyze variant associations within 1 megabase (Mb) of each gene's transcription start site (TSS).  
 - [**trans-xQTL analysis.**](https://github.com/corbinq/yax/blob/master/doc/mode_trans.md)  `./yax trans {options}`
	 - Analyze xQTL genome-wide associations for each molecular trait, optionally excluding variants within the cis region.   
 - [**xQTL meta-analysis.**](https://github.com/corbinq/yax/blob/master/doc/mode_meta.md)  `./yax meta {options}`
	 -  Meta-analyze xQTL association summary statistics across one or multiple studies.   
 - [**xQTL summary data storage.**](https://github.com/corbinq/yax/blob/master/doc/mode_store.md)  `./yax store {options}`
	 -  Store genotypic variance-covariance (LD) data matrices for data-sharing or meta-analysis. These files enable accurate multiple-variant analysis from xQTL summary statistics, including joint and conditional regression analysis, Bayesian finemapping, aggregation tests, and penalized regression / variable selection.    
 
## Documentation pages
 Tutorials for each analysis mode (cis, trans, meta, store) are listed in the previous paragraph ([Analysis modes](##analysis-modes)).  Additional documentation pages are listed below. 
 - **[Input file formats for individual-level analysis](https://github.com/corbinq/yax/blob/master/doc/input_files.md)** in modes `yax cis`, `yax trans`, and `yax store`. 
 - **[YAX xQTL summary association data file formats](https://github.com/corbinq/yax/blob/master/doc/sumstat_files.md)**. 
 - **[Bayesian finemapping using YAX xQTL summary association data files](https://github.com/corbinq/yax/blob/master/doc/example_finemapping.md)**. 
 
## Installation
YAX is primarily written in C++. To compile YAX from source, run:
```
    git clone https://github.com/corbinq/yax.git
    cd yax 
    bash get_dependencies.sh
    make
```
Precompiled binaries are also available as follows:

## Software dependencies

 - [Eigen C++ matrix library](http://eigen.tuxfamily.org/)
 - [HTSlib C library](http://www.htslib.org/)
 - [github.com/jonathonl/shrinkwrap](https://github.com/jonathonl/shrinkwrap)
 - [github.com/Taywee/args](https://github.com/Taywee/args)
 - [Boost math C++ library](https://www.boost.org/)

## Contact, feedback, bug reports
YAX is a work in progress, and under active development. Feedback, suggestions and bug reports are greatly appreciated. Contact: [qcorbin@hsph.harvard.edu](qcorbin@hsph.harvard.edu).  

## Acknowledgements
 - Li Guan
 - Laura Scott
 - Xihao Li
 - Zilin Li
 - Rounak Dey
 - Xihong Lin


