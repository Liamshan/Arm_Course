/*
several hours spent understanding clocks and timers in the mbed module 6. Here are the notes.
Mbed Module 6 Notes



Alright, there are 4 standard components in a timer. 





there is the clock source



 I’m assuming that this is like the real time clock or maybe the embedded timer chip thing 



The Prescaler



this apparently takes the clock source as it’s input and scales the frequency down into a setting required for the timer task. see, this is the kind of bullshit technical jargen that is confusing to follow. like you’re introducing this concept to me and you’re like this prescaler slacels the frequency down into a setting required for the timer task. what the actual fuck does that mean. there is no context no simplified example. just the prescaler scales  the frequency down. does that mean it’s increasing or decreasing the rate at which the clock is ticking. the fuck.  does it be dividint the input frequency by a predefined value. so like idk becuasee this is ticking so what the fuck you are like im getting 10 ticks per second i’m gonna divide that by 2 that would mean i’m getting 5 ticks per second, but you’re not, you’re getting 10, so does it output a ediffernet frequency? like, does it skip every other tick? Maybe ya, like not everything needs to be running on 50 thousand kilahertz. maybe this toaster just needs to count seconds or whatever. so the prescaler can be like, yo, give me every 10thousanth tick and funnel it to this toaster. so the timer register is incremented or decremented at a fixed frequency. I guess that means that it’s just counting. like the register which is just a piece of memory that is storing the counter value. and i think the register is for the given device. no 



Timer Register



the timer register is the thing we were seeing on the other embedded systems courses. it’s the timer that the board is operating on. like, you just define the speed that the board is running at and dthen each line of the operation or each tick, it executes the next like and maybe the next line is to count a tick, or maybe it’s to execute a command, but every ding tick is a new line of code. this is driven by the output of the prescaler called ticks



Capture register



the capture register loads the current values from the timer register. i guess if the timer register reaches 10 then we capture that value and do something. Idk, they’re called events. 



Compare Register



This reads the timer on events and periodically compares the timer with a given value, and if the timer hits that value, an interrupt is created. 



ok, so in this we are actually using the timer. wait 10 seconds, or 10 ticks, and then call an interrupt. now that I can actually understand and get behind as a thing that is used in a program. 
*/