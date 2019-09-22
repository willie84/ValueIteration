//
//  valueIteration.cpp
//  valueIteration
//
//  Created by Willie Macharia on 2019/09/21.
//  Copyright © 2019 Willie Macharia. All rights reserved.
//

#include "valueIteration.h"
#include "State.h"
#include <vector>
#include <fstream>
//#include <fstream>  // Needed for file stream objects
#include <iostream> // Needed for console stream objects
#include <sstream>
#include "float.h"
#include <iostream>
#include <algorithm>

std::vector<std::vector<MCHWIL006::state> > createAGrid(){
    std::vector<std::vector<MCHWIL006::state>> grid;
    MCHWIL006::state one,two,three,four,five,six;
    //Up=0, down=1, right=2, left=3  TERMINAL STATE=-1
    one=MCHWIL006::state({2,1},{},0,1);
    two=MCHWIL006::state({1,2,3},{{3,50}},0,2);

    three=MCHWIL006::state({-1},{},0,3);
    four=MCHWIL006::state({0,2},{},0,4);
    five=MCHWIL006::state({0,2,3},{},0,5);
    six=MCHWIL006::state({0,2},{{3,100}},0,6);

    grid[0][0]=one;
    grid[0][1]=two;
    grid[0][2]=three;
    grid[1][0]=four;
    grid[1][1]=five;
    grid[1][2]=six;


    return grid;

    }


void iterate(){
  //std::string outname;
  //myfile<<"Enter the outputfilename"<<"\n";
  //std::cin>>outname;
   std::ofstream myfile ("Answers.txt");
   myfile << "Question 1"<<"\n";
    double discount=0.8;
    std::vector<std::vector<MCHWIL006::state>> gridz;
    std::vector<MCHWIL006::state> gri;
    std::vector<MCHWIL006::state> griz;
    MCHWIL006::state one,two,three,four,five,six;
    //Up=0, down=1, right=2, left=3  TERMINAL STATE=-1
    one=MCHWIL006::state({2,1},{},0,1);
    two=MCHWIL006::state({1,2,3},{{3,50}},0,2);

    three=MCHWIL006::state({-1},{},0,3);
    four=MCHWIL006::state({0,2},{},0,4);
    five=MCHWIL006::state({0,2,3},{},0,5);
    six=MCHWIL006::state({0,3},{{3,100}},0,6);

    gri.push_back(one);gri.push_back(two);gri.push_back(three);
    griz.push_back(four);griz.push_back(five);griz.push_back(six);
    gridz.push_back(gri);gridz.push_back(griz);
    std::vector<std::vector<double>> gridcomp;
    std::vector<std::vector<double>> tempcomp;

    for(int p=0;p<gridz.size();p++){
        std::vector<double> gridcomp11;
        for(int pw=0;pw<gridz[p].size();pw++){
            gridcomp11.push_back(0);  //set the Initital set of the Grid to zero all of them.

        }
        gridcomp.push_back(gridcomp11);
    }


    for(int p=0;p<gridz.size();p++){
        std::vector<double> gridcomp1;
        for(int pw=0;pw<gridz[p].size();pw++){
            gridcomp1.push_back(1);  //set the Initital set of the Grid to zero all of them.

        }
        tempcomp.push_back(gridcomp1);
    }

    int iteration=0;
    while(!MCHWIL006::grids_converge(gridcomp, tempcomp)){

        gridcomp=tempcomp;
        for(int row=0;row<gridz.size();row++){

            for(int col=0;col<gridz[row].size();col++){
                MCHWIL006::state next_state;
                for(int a: gridz[row][col].state_actions){

                    if(a==0){ //Up mvement action
                        next_state=gridz[row-1][col];
                        gridz[row][col].state_value= std::max (gridz[row][col].state_value,gridz[row][col].state_reward[next_state.statenum]+discount*next_state.state_value);

                        double h=std::max (gridz[row][col].state_value,gridz[row][col].state_reward[next_state.statenum]+discount*next_state.state_value);
                        //myfile << h << "  Action"<<a<<'\n';
                    }
                    if(a==1){  //Down movement
                        next_state=gridz[row+1][col];
                        gridz[row][col].state_value= std::max (gridz[row][col].state_value,gridz[row][col].state_reward[next_state.statenum]+discount*next_state.state_value);

                        double h2=std::max (gridz[row][col].state_value,gridz[row][col].state_reward[next_state.statenum]+discount*next_state.state_value);
                        //myfile << h2 << "  Action"<<a<<'\n';
                    }

                    if(a==3){  //left action
                        next_state=gridz[row][col-1];
                        gridz[row][col].state_value= std::max (gridz[row][col].state_value,gridz[row][col].state_reward[next_state.statenum]+discount*next_state.state_value);

                        double h3=std::max (gridz[row][col].state_value,gridz[row][col].state_reward[next_state.statenum]+discount*next_state.state_value);
                        //myfile << h << "  Action"<<a<<'\n';
                        //myfile << h3 << "  Action"<<a<<'\n';
                    }

                    if(a==2){  //right action
                        next_state=gridz[row][col+1];
                        gridz[row][col].state_value= std::max (gridz[row][col].state_value,gridz[row][col].state_reward[next_state.statenum]+discount*next_state.state_value);

                        double h4=std::max (gridz[row][col].state_value,gridz[row][col].state_reward[next_state.statenum]+discount*next_state.state_value);
                        //myfile << h << "  Action"<<a<<'\n';
                        //myfile << h4 << "  Action"<<a<<'\n';
                    }



                }

            }
        }
        iteration++;
        myfile << "--------------------------------------------------------------"<<"\n";
        myfile << "--------------------------------------------------------------"<<"\n";
        myfile << "Iteration Number "<<iteration<<"\n";
        for (size_t column = 0; column < 2; column++) {
            /* code */
            for (size_t row = 0; row < 3; row++) {
                /* code */
                tempcomp[column][row] =gridz[column][row].state_value;
                myfile << gridz[column][row].state_value << " |";
            }
            myfile << '\n'<<"\n";
        }



    }

    myfile<<"The iterations required for convergence are "<< iteration<<"\n";
    myfile << "The V* for iteration 4 and 5 are the same hence they converge."<<"\n";
    myfile << " "<<"\n";

    for(int p=0;p<gridz.size();p++){
      for(int pc=0;pc<gridz[p].size();pc++){
        myfile<<"State Number :"<<gridz[p][pc].statenum<<"  V*: "<<gridz[p][pc].state_value<<"\n";

      }
    }



   std::vector<MCHWIL006::state> optimal=findOptimal(one,gridz);
   optimal.push_back(three);  //adding the Terminal states here

myfile << "--------------------------------------------------------------"<<"\n";
myfile << "--------------------------------------------------------------"<<"\n";

myfile << " "<<"\n";
myfile << " "<<"\n";
myfile << "Question 2"<<"\n";
//myfile << "--------------------------------------------------------------"<<"\n";
 myfile << "The optimal policy to follow is " << '\n';
 for(int y=0;y<optimal.size()-1;y++){

   myfile<< "S"<<optimal[y].statenum<< "->";
 }
 myfile<< "S"<<optimal[optimal.size()-1].statenum;


 myfile << " " << '\n';


 myfile << " "<<"\n";
 myfile << " "<<"\n";


myfile << "Question 3"<<"\n";
myfile << " Yes.  You can multiply by a scalar each immediate reward. Then V* is also multiplied by scalar and π∗ remains unchanged"<<"\n";
myfile << " For example.  You can multiply by a two each immediate reward. Then V* is also multiplied by two and π∗ remains unchanged"<<"\n";


}


int main(int argc, const char * argv[]) {
    // insert code here...
    iterate();

    std::cout << "The Value iteration process has been finished sucessfully. The answers have been saved in the Answers.txt file" << '\n';
    return 0;
}

bool MCHWIL006::grids_converge(std::vector<std::vector<double>> gridc,std::vector<std::vector<double>> gridcom){
    for (size_t column = 0; column < gridc.size(); column++) {
        /* code */
        for (size_t row = 0; row < gridc[column].size(); row++) {
            /* code */
            if (gridc[column][row] !=gridcom[column][row]) {
                /* code */
                return false;
            }
        }
    }
    return true;
}

std::vector<MCHWIL006::state>  MCHWIL006::findOptimal(MCHWIL006::state startingpoint,std::vector<std::vector<MCHWIL006::state>> gridco){

 std::vector<MCHWIL006::state> heret;


      while(startingpoint.statenum !=3){
        heret.push_back(startingpoint);
        std::vector<double>  values;
        MCHWIL006::state next_state;

        for(int a: startingpoint.state_actions){
          double statev;
          if(a==0){ //Up mvement actions
            for(int b=0;b<gridco.size();b++){
              for(int bx=0;bx<gridco[b].size();bx++){

               if(gridco[b][bx].statenum==startingpoint.statenum){
                 next_state=gridco[b-1][bx];
                 break;
               }
              }
            }

              statev=next_state.state_value;
              values.push_back(statev);
              //myfile << h << "  Action"<<a<<'\n';
          }

          if(a==1){ //down mvement action
            for(int b=0;b<gridco.size();b++){
              for(int bx=0;bx<gridco[b].size();bx++){

               if(gridco[b][bx].statenum==startingpoint.statenum){
                 next_state=gridco[b+1][bx];
                 break;
               }
              }
            }
              //next_state=gridz[row+1][col];
              statev=next_state.state_value;
              values.push_back(statev);
              //myfile << h << "  Action"<<a<<'\n';
          }

          if(a==2){ //right mvement action
            for(int b=0;b<gridco.size();b++){
              for(int bx=0;bx<gridco[b].size();bx++){

               if(gridco[b][bx].statenum==startingpoint.statenum){
                 next_state=gridco[b][bx+1];
                 break;
               }
              }
            }
              //next_state=gridz[row][col+1];
              statev=next_state.state_value;
              values.push_back(statev);
              //myfile << h << "  Action"<<a<<'\n';
          }

          if(a==3 && startingpoint.statenum !=6){ //preventing state six from moving back
            for(int b=0;b<gridco.size();b++){
              for(int bx=0;bx<gridco[b].size();bx++){

               if(gridco[b][bx].statenum==startingpoint.statenum){
                 next_state=gridco[b][bx-1];
                 break;
               }
              }
            }
              //next_state=gridz[row][col-1];
              statev=next_state.state_value;
              values.push_back(statev);
              //myfile << h << "  Action"<<a<<'\n';
          }

        }

       double t=*max_element(values.begin(), values.end());

       for(int px=0;px<gridco.size();px++){
         for(int pxz=0;pxz<gridco[px].size();pxz++){

           if(gridco[px][pxz].state_value==t){
             startingpoint=gridco[px][pxz];
             //myfile << t << '\n';
             break;
           }

         }
       }
     }

return heret;

}
