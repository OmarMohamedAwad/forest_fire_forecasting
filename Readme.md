# Forest Fire Forcasting

<p align="center">

<img src="ReadMe-photos/home updates.png">

</p>


## Auther: Omar Awad.
            
## Assumtions
#
## The Server Side Assumtion:

1- The server connects to clients through a socket protocol.
2- There is no hardware device so the solution is simulate a function that generates temperature within range.
3- The data that will be received from clients is a raw data string and speratio delimiter will be ":" or ",".

## The Client Side Assumtion:

1- The client connects to nodes through a socket channel.
2- The client calculates the average temperature based on the last five reading to ensure the data is valid and make sense.
3- The client calculates the accumulated temperature based on the number of sensors connected.
