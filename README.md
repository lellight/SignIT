# SignIT
Mutation Signatures in Individual Tumours

## Installation

### Development Version

To install from GitHub, first make sure that you can install the rstan package and C++ toolchain by following [these instructions](https://github.com/stan-dev/rstan/wiki/RStan-Getting-Started). Also, be sure to install BSgenome from Bioconductor. If it is not installed, you can use the following commands in R:

```{r}
source("https://bioconductor.org/biocLite.R")
biocLite('BSgenome')
```

Once rstan and BSgenome are successfully installed, you can install SignIT from GitHub using the devtools package by executing the following in R:

```{r}
if (!require(devtools)) {
  install.packages("devtools")
  library(devtools)
}
install_github("eyzhao/SignIT", recompile = TRUE, build_vignettes = FALSE)
```

### Setting up R and Necessary Dependencies

A convenient way to set up a standalone installation of R with SignIT is to use an Anaconda environment. In a Bash shell, the following commands will check out such an environment and install it locally.

```{bash}
git clone https://github.com/eyzhao/bio-pipeline-dependencies.git
cd bio-pipeline-dependencies
git checkout tags/SignIT-paper-dependencies
make
```

After this is complete, run the following command to activate the environment and run R.

```{bash}
source miniconda3/bin/activate dependencies
R
```
