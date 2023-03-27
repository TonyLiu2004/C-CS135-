/*
Author: Tony Liu
Course: CSCI-135
Instructor: Genady Maryash
Assignment: E9.3

Simulate a circuit for controlling a hallway light that has switches at both ends of the hallway. 
Each switch can be up or down, and the light can be on or off. Toggling either switch turns the lamp on or off. 
Provide member functions: int get_first_switch_state() /*0 for down, 1 for up; int get_second_switch_state(); 
int get_lamp_state() /*0 for off, 1 for on; void toggle_first_switch(); void toggle_second_switch()

*/
#include <iostream>
using namespace std;

class Circuit {
	public:
		int get_first_switch_state();
		int get_second_switch_state();
		int get_lamp_state();
		void toggle_first_switch();
		void toggle_second_switch();
	private:
		int first_switch = 0;
		int second_switch = 0;
		int lamp_state = 0;
};

int Circuit::get_first_switch_state() /*0 for down, 1 for up*/
{
    return first_switch;
}

int Circuit::get_second_switch_state(){
    return second_switch;
}

int Circuit::get_lamp_state() /*0 for off, 1 for on*/
{
    return lamp_state;
}

void Circuit::toggle_first_switch(){
    if(first_switch){
        first_switch = 0;
        if(lamp_state == 0){
            lamp_state = 1;
        }else{
            lamp_state = 0;
        }
    }else{
        first_switch = 1;   
        if(lamp_state == 0){
            lamp_state = 1;
        }else{
            lamp_state = 0;
        }
    }
}

void Circuit::toggle_second_switch(){
    if(second_switch){
        second_switch = 0;
        if(lamp_state == 0){
            lamp_state = 1;
        }else{
            lamp_state = 0;
        }
    }else{
        second_switch = 1;
        if(lamp_state == 0){
            lamp_state = 1;
        }else{
            lamp_state = 0;
        }
    }
}

int main(){
    return 0;
}