how to use:<br/>
use vcreate() to create a vector<br/>
use vpush() to append value<br/>
use vget() to get value with the specified index<br/>
use vpop() to remove the last value<br/>
use vfreeElement() to free all element inside specified vector<br/>
use vreset() to set length to 0<br/>
use vfree() to free the vector.data heap allocation<br/><br/>

example is in the test.c file<br/>
<br/>
to compile and link:<br/>
clang \<your c files\> vector.c -o \<output\>
