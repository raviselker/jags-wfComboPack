# JAGS wfComboPack module

The JAGS wfComboPack module is an extension for JAGS that implements 7
deterministic functions representing different decision strategies:

  - Take-the-best
  - TALLY
  - TALLYk
  - Weighted Additive
  - k-Reason
  - Random Walk
  - General Accumulator

Documentation on every function can be found in the [wiki](https://github.com/raviselker/jags-wfComboPack/wiki/Documentation-functions)

## Build instructions

### Linux and MacOS

#### From tarball

Download the [tarball](https://github.com/raviselker/jags-wfComboPack/releases/download/v0.9.0/JAGS-WFCOMBOPACK-MODULE-0.9.0.tar.gz), extract it, and open a terminal.

```sh
# change the working directory
cd path/to/jags-wfComboPack

sudo ./configure && sudo make && sudo make install
```
Note: It might be necessary to define a different prefix, depending on where JAGS is copied (i.e. installed), for example:
```sh
sudo ./configure --prefix /usr && sudo make && sudo make install
```

#### From repository

Download or clone this repository on your computer and open a terminal.

```sh
# change the working directory
cd path/to/jags-wfComboPack

# dependencies (on a clean ubuntu installation)
sudo apt-get install autoconf automake libtool g++

# creating all auxiliary files
autoreconf -fvi

# building
sudo ./configure
sudo make

# or, if JAGS has been installed in a different location, e.g. /usr
sudo ./configure --prefix /usr
sudo make

# install
sudo make install
```
