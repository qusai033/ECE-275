/* Personal Space Show from Rick and Morty:
 *
 * The show is hosted by a man named Phillip Jacobs who is extremely concerned with his personal space
 * and takes it very seriously. At times he's paranoid that someone is close to him, even though he is
 * alone. After the intro he will direct the camera towards a projector and show slides saying "personal
 * space", and telling the viewers to stay out of his personal space. At the end of the show he removes
 * his own skin on live TV because he does not care to have it on his personal space.
 */
#include <iostream>
#include <cstdlib>

using std::cout, std::endl;
        //1 2 3 5 10
        //argc = number of arguments
        //argv is data in arguments
int main(int argc, char* argv[]) {
    cout <<"Welcome to the Personal Space Show!!"<<endl;
    //for loop (argc)
    for (int i = 0; i < argc; i++) {
        int num = atoi(argv[i]);
       // if ((num > 0) && (num < 9)) {
            switch (num) {
                case 0:
                   //cout << num << ": Number not recognized" << endl;
                   break;
                case 1:
                    cout << "One: Personal space" << endl;
                    break;
                case 2:
                    cout << "Two: Personal space" << endl;
                    break;
                case 3:
                    cout << "Three: Stay out of my personal space" << endl;
                    break;
                case 4:
                    cout << "Four: Keep away from my personal space" << endl;
                    break;
                case 5:
                    cout << "Five: Get outta dat personal space" << endl;
                    break;
                case 6:
                    cout << "Six: Stay away from my personal space" << endl;
                    break;
                case 7:
                    cout << "Seven: Keep away from dat personal space" << endl;
                    break;
                case 8:
                    cout << "Eight: Personal space" <<endl;
                    break;
                case 9:
                    cout << "Nine: Personal space" << endl;
                    break;
                default:
                    cout << num << ": Number not recognized" << endl;
           // }
        }
    }
    return 0;
}
