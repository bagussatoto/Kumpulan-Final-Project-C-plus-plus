#include <iostream>
#include <vector>
#include <sstream>


#define firstD 5
#define secondD 10
#define space 20-menuMakan[i][j].size() 
using namespace std;

    struct dotted:numpunct<char> {
        char do_thousands_sep() const { 
            return '.'; 
            } 
        
        string do_grouping() const { 
            return "\3"; 
            }

        static void imbue(ostream &os) {
            os.imbue(locale(os.getloc(), new dotted));
        }
    };

    void dot(int* x){
        stringstream ss;
        dotted::imbue(ss);
        ss << *x;
        cout << ss.str();
    }

    void spacingMakanan(string x){
        for (int i = 0; i < 25-x.size(); i++)
        {
            cout << " ";
        }
    }
    
    void spacingHarga(){
        for (int i = 0; i < 3; i++)
        {
            cout << " ";
        }
    }

    void spacingTotal(){
        for (int i = 0; i < 27; i++)
        {
            cout << " ";
        }
    }

    string menuMakan[firstD][secondD]={{"Ayam Goreng", "Ayam Bakar", "Ayam Lada Hitam", "Ayam Penyet", "Ayam Koloke", "em", "em", "em", "em", "em"},
                            {"Cumi Tepung", "Cumi Goreng", "Cumi Asam Manis", "Cumi Saus Padang", "em", "em", "em", "em", "em", "em"},
                            {"Udang Goreng Tepung", "Udang Goreng Mentega", "Udang Asam Manis", "Udang Lada Hitam", "Udang Saus Padang", "em", "em", "em", "em", "em"}, 
                            {"Sapi Lada Hitam", "Sapi Mentega", "Sapi Ala Canton", "em", "em", "em", "em", "em", "em", "em"},
                            {"Es Teh", "Es Jeruk", "Es Kelapa muda", "Es Cincau", "Es campur", "Wedang Ronde", "Es Susu", "Es Teler", "Air Mineral", "em"}};
                            
    int hargaMakan[firstD][secondD] = {{6000,10000,12000,11000,12000}, {9000,9000,12000,13000}, 
                                        {15000,15000,20000,20000,22000}, {25000,23000,30000},
                                        {3000,3000,6000,5000,10000,4000,5000,7000,4000,0}, 
                                        };
    

void amogus(){
        cout <<"\n\t\t            |||||||||||| ";
        cout <<"\n\t\t          |||||||||||||||||| ";
        cout <<"\n\t\t         |||||||||||||||||||||";
        cout <<"\n\t\t    |||| ||||||||||      ==== ||";
        cout <<"\n\t\t  |||||| ||||||||         ===  |";
        cout <<"\n\t\t  |||||| ||||||||||           ||";
        cout <<"\n\t\t  |||||| |||||||||||||||||||||||";
        cout <<"\n\t\t  |||||| |||||||| RESTORAN |||||";
        cout <<"\n\t\t  |||||| ||||||||| PUNYA |||||||";
        cout <<"\n\t\t   ||||| |||||||||| RASA |||||||";
        cout <<"\n\t\t     ||| |||||||||||||||||||||||";
        cout <<"\n\t\t       | |||||||||||||||||||||||";
        cout <<"\n\t\t         |||||||||||| ||||||||||";
        cout <<"\n\t\t         |||||||||||| ||||||||||";
        cout <<"\n\t\t         ||||||||||    |||||||||";
        cout <<"\n\t\t         ||||||||||    |||||||||";
    }

void amogusEmpty(){                              
        cout <<"\n\t                                    ____";                  
        cout <<"\n\t                                   ((   ))";
        cout <<"\n\t                                       ))";  
        cout <<"\n\t                                     ||";   
        cout <<"\n\t\t            ||||||||||||     00";
        cout <<"\n\t\t          |||||||||||||||||| ";
        cout <<"\n\t\t         |||||||||||||||||||||";
        cout <<"\n\t\t    |||| ||||||||||      ==== ||";
        cout <<"\n\t\t  |||||| ||||||||         ===  |";
        cout <<"\n\t\t  |||||| ||||||||||           ||";
        cout <<"\n\t\t  |||||| |||||||||||||||||||||||";
        cout <<"\n\t\t  |||||| |||||||| RESTORAN |||||";
        cout <<"\n\t\t  |||||| ||||||||| PUNYA |||||||";
        cout <<"\n\t\t   ||||| |||||||||| RASA |||||||";
        cout <<"\n\t\t     ||| |||||||||||||||||||||||";
        cout <<"\n\t\t       | |||||||||||||||||||||||";
        cout <<"\n\t\t         |||||||||||| ||||||||||";
        cout <<"\n\t\t         |||||||||||| ||||||||||";
        cout <<"\n\t\t         ||||||||||    |||||||||";
        cout <<"\n\t\t         ||||||||||    |||||||||";
        cout <<"\n\t\t        ========================"; 
        cout <<"\n\t\t       /                        \\"; 
        cout <<"\n\t\t      |  D A T A   K O S O N G  |"; 
        cout <<"\n\t\t      ==========================="; 
}
void amogusExit(){
        cout <<"\n\t\t                  ||||||||||||     ";
        cout <<"\n\t\t                |||||||||||||||||| ";
        cout <<"\n\t\t               |||||||||||||||||||||";
        cout <<"\n\t\t          |||| ||||||||||      ==== ||";
        cout <<"\n\t\t        |||||| ||||||||         ===  |";
        cout <<"\n\t\t        |||||| ||||||||||           ||";
        cout <<"\n\t\t        |||||| |||||||||||||||||||||||";
        cout <<"\n\t\t        |||||| |||||||| RESTORAN |||||";
        cout <<"\n\t\t        |||||| ||||||||| PUNYA |||||||";
        cout <<"\n\t\t         ||||| |||||||||| RASA |||||||";
        cout <<"\n\t\t           ||| |||||||||||||||||||||||";
        cout <<"\n\t\t             | |||||||||||||||||||||||";
        cout <<"\n\t\t     ///////   |||||||||||| ||||||||||";
        cout <<"\n\t\t    ///////    |||||||||||| ||||||||||";
        cout <<"\n\t\t   ///////     ||||||||||    |||||||||";
        cout <<"\n\t\t               ||||||||||    |||||||||";
}
