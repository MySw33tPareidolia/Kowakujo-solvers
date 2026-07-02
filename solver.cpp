#include <iostream>
#include <vector>
#include <string>
void killer(){
std::vector <std::string> killer_plate = {"Comb", "x", "y", "z", "Medallion"};
std::cout << "Who is the Accomplice?\n" << "1. Gardener\n" << "2. Merchant\n" << "3. Courtier\n";
int Accomplice;
std::cin >> Accomplice;

if(Accomplice == 1)
{
killer_plate[1] = "Gardening Shears";


}

else if(Accomplice == 2){

killer_plate[1] = "Mercantile Abacus";
}


else {
killer_plate[1] = "Nobles Hat";

}

int Cause_Of_Death;
std::cout << "What is the cause of death?\n" << "1. ...Contaminated or noxious food and showed signs of emesis\n" << "2. ...contaminated or noxious plant\n" << "3. ...showed evidence of paralysis\n";
std::cin >> Cause_Of_Death;

if(Cause_Of_Death == 1)
{
killer_plate[2] = "Pufferfish";


}

else if(Cause_Of_Death == 2){

killer_plate[2] = "Plum Pit";
}


else {
killer_plate[2] = "Monkshood Flower";

}

int where_is_he;
std::cout << "What is in the 4th portrait?\n" << "1. Koi (fish)\n" << "2. Mountain\n" << "3. Bird" << "\n";
std::cin >> where_is_he;

if(where_is_he == 1)
{
killer_plate[3] = "Tea Whisk";


}

else if(where_is_he  == 2){

killer_plate[3] = "Horse Statuette";
}


else {
killer_plate[3] = "Calligraphy Brush";

}

std::cout << "From left to right: " << killer_plate[0] << "     "<< killer_plate[1] << "     " << killer_plate[2] << "     " << killer_plate[3] << "     " << killer_plate[4];

}

void Clock(){
int hour_death;
int hours_before_death;
std::vector<std::string> clock = {
        "Ox", "Tiger", "Rabbit", "Dragon",
        "Snake", "Horse", "Sheep", "Monkey",
        "Rooster", "Dog", "Boar", "Rat"
    };

    std::cout << "Time of Death?\n";
    std::cout << "0. Ox\n"
              << "1. Tiger\n"
              << "2. Rabbit\n"
              << "3. Dragon\n"
              << "4. Snake\n"
              << "5. Horse\n"
              << "6. Sheep\n"
              << "7. Monkey\n"
              << "8. Rooster\n"
              << "9. Dog\n"
              << "10. Boar\n"
              << "11. Rat\n";

    std::cin >> hour_death;

    if (hour_death < 0 || hour_death > 11) {
        std::cout << "Invalid time of death.\n";
        return;
    }

    std::cout << "Symptoms usually take effect within __ hours?\n";
    std::cin >> hours_before_death;

    
    int current_hour = (hour_death - hours_before_death) % 12;

    if (current_hour < 0) {
        current_hour += 12;
    }

    std::cout << "The poison was administered during the Hour of the "
              << clock[current_hour] << ".\n";
}

void Scroll() {
    const int N = 9;

    std::vector<int> state(N, 0);

    std::cout << "Choose the scrolls that are OUT (e.g. ABE or ACE):\n";
    std::cout << "A B C\nD E F\nG H I\n";
    std::string input;
    std::cin >> input;

    for (char &c : input) c = toupper(c);

    auto idx = [](char c) { return c - 'A'; };

    for (char c : input) {
        state[idx(c)] ^= 1;
    }

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));

    auto add = [&](int p, std::vector<int>& row) {
        int r = p / 3, c = p % 3;
        row[p] = 1;
        if (r > 0) row[p - 3] = 1;
        if (r < 2) row[p + 3] = 1;
        if (c > 0) row[p - 1] = 1;
        if (c < 2) row[p + 1] = 1;
    };

    for (int i = 0; i < N; i++) add(i, A[i]);

    std::vector<int> b = state;

    int r = 0;
    std::vector<int> where(N, -1);

    for (int c = 0; c < N && r < N; c++) {
        int pivot = -1;
        for (int i = r; i < N; i++) {
            if (A[i][c]) { pivot = i; break; }
        }
        if (pivot == -1) continue;

        std::swap(A[r], A[pivot]);
        std::swap(b[r], b[pivot]);
        where[c] = r;

        for (int i = 0; i < N; i++) {
            if (i != r && A[i][c]) {
                for (int j = 0; j < N; j++) {
                    A[i][j] ^= A[r][j];
                }
                b[i] ^= b[r];
            }
        }

        r++;
    }

    std::vector<int> x(N, 0);

    for (int i = 0; i < N; i++) {
        if (where[i] != -1) {
            x[i] = b[where[i]];
        }
    }

    std::cout << "\nSOLUTION GRID:\n\n";

    for (int i = 0; i < 9; i++) {
        int r = i / 3, c = i % 3;
        std::cout << (x[i] ? "X " : "O ");
        if (c == 2) std::cout << "\n";
    }
}

int main(){
std::cout << R"(

██╗  ██╗ ██████╗ ██╗    ██╗ █████╗ ██╗  ██╗██╗   ██╗     ██╗ ██████╗
██║ ██╔╝██╔═══██╗██║    ██║██╔══██╗██║ ██╔╝██║   ██║     ██║██╔═══██╗
█████╔╝ ██║   ██║██║ █╗ ██║███████║█████╔╝ ██║   ██║     ██║██║   ██║
██╔═██╗ ██║   ██║██║███╗██║██╔══██║██╔═██╗ ██║   ██║██   ██║██║   ██║
██║  ██╗╚██████╔╝╚███╔███╔╝██║  ██║██║  ██╗╚██████╔╝╚█████╔╝╚██████╔╝
╚═╝  ╚═╝ ╚═════╝  ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝  ╚════╝  ╚═════╝
)" << '\n';

std::cout << "What solver do you wanna use?\n" << "1. Killer solver\n" << "2. Clock solver\n" << "3. Scroll puzzle solver" << "\n";
int start;
std::cin >> start;

if(start > 3){
std::cout << "Invalid Choice!\n";
}

else {

switch(start){

case 1:
killer();
break;

case 2:
Clock();
break;

case 3:
Scroll();
break;


}



}
}
