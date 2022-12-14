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
2. There is no hardware device so the solution is a simulation by a function that generates temperature within a given range.
3. The data will be received from clients as a raw data string and the speration delimiter will be ":" or ",".

## The Client Side Assumtion:

1. The client connects to nodes through a socket channel.
2. The client calculates the average temperature based on the latest five readings to ensure the data is valid and make sense.
3. The client calculates the accumulated temperature based on the number of connected sensors.

## System Design
<img src="document/readme/System Design-System Design.drawio.png">

## System Components
<img src="document/readme/System Componants.png">

## System Implementation
### Server Class Digram
<img src="document/readme/Class Digram-Server.png">

### Client Class Digram
<img src="document/readme/Class Digram-Client.png">


