
#include "Dir_t.hpp"

int main()
{
    Dir_t d;

    d.add("Ahmed", "0689971837", "abdo@gmail.com");
    d.add("Said", "0658743651", "said@gmail.com");
    d.add("Sami", "065754871", "sami@gmail.com");
    d.add("Samira", "065876588", "samira@gmail.com");
    d.add("Amin", "0697484135", "amin@gmail.com");
    d.add("Bahija", "0654478154", "bahija@gmail.com");
    d.add("Fatima", "054678465", "fatima@gmail.com");

    // d.print();
    // d.deleteList("bahija@gmail.com" ,"Bahija");
    // d.deleteList("abdo@gmail.com" , "Ahmed");
    // d.deleteList("samira@gmail.com" , "Samira");
    // d.print();
    // d.update("Amida", "abdo@gmail.com", "05555555");
    cout << "\n\n";
    d.print();
    return 0;
}