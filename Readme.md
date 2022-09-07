# Forest Fire Forcasting :evergreen_tree: :fire:

## Auther: Omar Awad.

## Description:
- The company has decided to invest into forest fire forecasting.
- The first step is to gather data about the temperature from the sensory node located in the forest. 
The node will be acting as server sending temperature grades (Celsius), each one second to a client. 

 
**The client shall calculate the following , as it gets the data:**
- Average over time. 
- Accumulation over time. 
The client shall print the calculations each 5 seconds. 

**Languages used: C++** 
 
## Assumtions
## The Server Side Assumtion:

1. The server connects to clients through a socket protocol.
2. There is no hardware device so the solution is simulate a function that generates temperature within range.
3. The data that will be received from clients is a raw data string and speratio delimiter will be ":" or ",".

## The Client Side Assumtion:

1. The client connects to nodes through a socket channel.
2. The client calculates the average temperature based on the last five reading to ensure the data is valid and make sense.
3. The client calculates the accumulated temperature based on the number of sensors connected.

