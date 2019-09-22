//
//  State.h
//  valueIteration
//
//  Created by Willie Macharia on 2019/09/21.
//  Copyright © 2019 Willie Macharia. All rights reserved.
//

#ifndef State_h
#define State_h
#include <vector>
#include <map>
#include <iostream>

namespace MCHWIL006 {


class state{
public:
    std::vector<int> state_actions; //actions for a state
    std::map<int, int> state_reward; //Reward after an action.
    int statenum;  //Indicates the state number
    double state_value;
    state(std::vector<int>, std::map<int, int>, double, int);
    state();
    ~state();

};

}
#endif

//#endif /* State_h */
