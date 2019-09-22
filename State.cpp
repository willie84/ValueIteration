//
//  State.cpp
//  valueIteration
//
//  Created by Willie Macharia on 2019/09/21.
//  Copyright © 2019 Willie Macharia. All rights reserved.
//

#include "State.h"

MCHWIL006::state::state(std::vector<int> actions, std::map<int, int> reward, double value, int state_number) :state_actions(actions),state_reward(reward),state_value(value),statenum(state_number){

}
MCHWIL006::state::state(){
  
}
MCHWIL006::state::~state(){



}
