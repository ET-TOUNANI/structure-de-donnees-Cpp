
#include "Dir_t.hpp"

int main()
{
    Dir_t d;

    d.add("Ahmed", "0689971837", "abdo@gmail.com");
    d.add("S1", "0658743651", "said@gmail.com");
    d.add("S2", "065871", "samir@gmail.com");
    d.add("S12", "065876588", "samira@gmail.com");
    d.add("S3", "088", "samar@gmail.com");
    d.add("S5", "088", "sami@gmail.com");
    d.add("S33", "088", "samar@gmail.com");
    d.add("S55", "088", "sami@gmail.com");
    // d.print();
    //  d.deleteList("said@gmail.com");
    d.print();
    return 0;
}