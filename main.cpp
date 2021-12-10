

// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
    

#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>

using namespace std;

void display_menu();
char get_selection();
void print_numbers(vector <int> &vec);
void add_number(vector <int> &v);
void mean_of_list(vector <int> &l);
void smallest_num(vector <int> &s);
void largest_num(vector <int> &largest);
void quit_menu();
void unknown();

void unknown(){
    cout << "Unknown selection please try again " << endl;
}

void quit_menu(){
    cout << "Goodbye" << endl;
}

void largest_num(vector <int> &largest){

    if(largest.size() == 0){
        cout << "Unable to determine the largest number - list is empty" << endl;
    }
    else{
    int largest_n{};
    largest_n = largest[0];
        for(size_t i{0}; i < largest.size(); ++i){
            if(largest_n < largest[i]){
                largest_n = largest[i]; 
            }
            
        }
        cout << "The largest number is :" << largest_n << endl;
        
    }
    cout << endl;
    
    
    
    
}



void smallest_num(vector <int> &s){
    if(s.size()==0){
        cout << "Unable to determine the smallest number - list is empty" << endl;
    }
    else{
        int smallest_n{};
        smallest_n = s[0];
        for(size_t i{0}; i < s.size(); ++i){
            if(smallest_n > s[i]){
                smallest_n = s[i];
            }
        }
        cout << "The smallest number is " << smallest_n << endl;
    }
    cout << endl;
}

void mean_of_list(vector <int> &l){
    int mean{};
    int sum{0};
    
    if(l.size()==0){
        cout << "Unable to calculate the mean - no data" << endl;
    }
    
    else{
    for(size_t i{0}; i < l.size(); ++i){
        sum += l[i];
    }
    mean = sum / 2;
    cout << "Mean of the list is : " << fixed << setprecision{3} << mean << endl;
    }
    cout << endl;
    
    
    
}

void add_number(vector <int> &v){
    int num{};
    cout << "Enter the number to be added to the list : ";
    cin >> num;
    v.push_back(num);
    cout << num <<  " added\n";
    cout << endl;    
}

void print_numbers(vector <int> &vec){
    if(vec.size()==0){
        cout << "[] - the list is empty" << endl;
    }
    
    else{
    cout << "[ ";    
    for(auto v:vec){
        cout << v << " ";
    }
    cout << " ]" << endl;
    }
    
    
    
}

char get_selection(){ 
    char choice{};
    cin >> choice;   
    return toupper(choice);
    
}

void display_menu(){
    cout << "To print numbers enter p or P\n";
    cout << "To add a number enter a or A\n"; 
    cout << "To display mean enter m or M\n"; 
    cout << "To display smallest number enter s or S\n";  
    cout << "To display largest number enter l or L\n"; 
    cout << "To quit pls enter q or Q\n";
    cout << "Enter your choice: ";
    
}

int main()
{
    vector <int> list{};
    char selection{};
    
    do{
        display_menu();
        selection = get_selection();
        
        switch(selection){
            
            case 'P' : print_numbers(list);
                       break;
            case 'A' : add_number(list);
                       break;
            case 'M' : mean_of_list(list);
                       break;          
            case 'S' : smallest_num(list);
                       break;
            case 'L' : largest_num(list);
                       break;
            case 'Q' : quit_menu();
                       break;
            deafault : unknown();
}
    }while(selection != 'Q');
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

