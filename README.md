# Push-up-counter
Many of us like to push-up the exercise. but sometimes we get tired,
and don’t make the right move down and up high enough, and don't 
remember the number of times. So, we made a counter to follow the 
rules. We choose Arduino to be the control circuit, an ultrasonic sensor 
to determine the number of times the body goes up and down and we 
will print the number of push-ups on the serial monitor.

# The device works as follows: 

 First the transmitter part of the sensor transmits some waves 
longitudinally in a straight line. The waves hit the body of the person and 
rebound to be received again by the sensor. The sensor measures the 
time needed to complete one round trip, and uses the given constant 
4
value of velocity of sound in air along with that time to calculate the 
distance between the person and the device. If the distance is less than 
15 cm it registers that the first half of the exercise is done properly, then 
the second half is recorded if the distance is greater than 30 cm. If both 
conditions are met, the counter increases by 1.
