1. Use case code: UC005

2. Use case name: Transter to internal account

3. Actor: Customer

4. Pre-condition: Customer logged in the system

5. Main flow of events (Success):

| No   | Actor  | Action                                          |
| ---- | ------ | ----------------------------------------------- |
| 1    | Customer   | Select transfer to internal account function |
| 2 | System | Display form to enter destination account |
| 3 | Customer | Enter the destination account |
| 4 | System | System ask to enter the amount of money to transfer |
| 5 | Customer | Enter the amount of money |
| 6 | System | Check the customer balance if the funds are insufficient |
| 7 | System | Send OTP (One-Time Password) to customer |
| 8 | Customer | Enter the OTP number |
| 9 | System | System check if OTP number that Customer enter is valid or not |
| 10 | System | Transfer to the destination account |
| 11 | System | System add a new transaction history |
| 12 | System | System decrease the transfer amount of the customer account |
| 13 | System | Notify successfully transfer |


6. Alternative flow of events:

| No   | Actor  | Action                                                       |
| ---- | ------ | ------------------------------------------------------------ |
| 6a.  | System | Output error: destination account is not exist, back to step enter destination account |
| 7a. | System | Output error: Notify insufficient funds, back to step enter amount of money to transfer |
| 10a. | System | Output error: Notify OTP is not correct, back to main menu   |


7. Post-condition: The system should be ready to perform another transaction or should be in a disabled state awaiting service.