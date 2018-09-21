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

### Build instructions

#### Linux and MacOS

Download or clone this repository on your computer and open a terminal.

```sh
# change the working directory
cd path/to/jags-wfComboPack

# dependencies (on a clean ubuntu installation)
sudo apt-get install autoconf automake libtool g++

# creating all auxiliary files
autoreconf -fvi

# building
./configure
make

# or, if JAGS has been installed in a different location, e.g. /usr
./configure --prefix /usr
make

# install
sudo make install
```
