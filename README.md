#
# Matrix Element Kinematic Discriminant (MEKD)
#
## Framework for using squared matrix elements for event classification.
#


get with

	$ git clone https://github.com/odysei/MEKD


### Build (standalone)

Bash procedure follows below.

* Setup the environment:
    
    $ . scripts/setup_flags.sh 

    $ . scripts/add_local_lib.sh


* Buil the library: libMEKD.so

	$ make -j N


### Directory structure
* **bin**:

* **data**:

* **doc**:

* **interface**:

* **lib**:

* **scripts**:

* **src**:

* **test**:

* **utils**:


### Usage

#### Instantiation

The MEKD class is instantiated by providing a vector of process descriptions,
like the following:

vector<process_description> my_processes;

...

MEKD my_MEs(my_processes);


#### Evaluation

Prepare your input, see input and input_c (MEKD_input.h), and your output
vector<double> (don't forget to reserve size), and run eval_MEs, like this:

input my_input;

vector<double> my_results;

...

eval_MEs(my_input, my_results);


#### Some details on evaluation

Internal computation sequence is the following:

**HEF_MEKD (4 leptons)** for **v2** and earlier:
1. eval_MEs(...) (user runs this)
2. ME_runners[i]->evaluate(...)
3. Run_ME_Configurator_HYPOTHESIS(...) (turn on/off couplings)
4. Run_ME_Configurator_SPIN(...) (generic coupling mixer)
5. Run_ME_Dispatcher_SPIN(...) (find and dispatch correct ME)
6. Run_MEs_Evaluator_Initial_State_TYPE(..., ME)

**v3**:
1. eval_MEs(...) (user runs this)
2. ME_runners[i]->evaluate(...)
3. template<> evaluate_PROCESS(...)
4. template<> Configurator_Spin0(...) (prepares Parameters_X: couplings, mass,
etc.)
5. template<> ME_Evaluator_IS_XX(...) (evaluates provided ME)


### Formatting

The following code style(s) is(are) used:

* For C/C++: Linux Kernel Style, see
https://www.kernel.org/doc/Documentation/CodingStyle

* For Python: PEP, see https://www.python.org/dev/peps/pep-0008/

* **RUN clang-format**: some automatization for C++ is available through
clang-format. Use it! Run:

	$ clang-format -style=file -i *.h

	$ clang-format -style=file -i *.cc

	$ clang-format -style=file -i *.cpp

to update all files in a current directory.
