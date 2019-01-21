1. Use case code: UC005

2. Use case name: Transter to external account

3. Actor: Customer, Bank consortium

4. Pre-condition: Customer logged in the system

5. Main flow of events (Success):

| No   | Actor  | Action                                          |
| ---- | ------ | ----------------------------------------------- |
| 1    | Customer   | Select transfer to external account function |
| 2 | System | Display form to enter destination bank and destination account |
| 3 | Customer | Enter the destination bank and destination account |
| 4 | System | Software ask the Bank consortium to display information of the destination account |
| 5 | Bank consortium | Return information of the destination account to system |
| 6 | System | Software display information of the destination account |
| 7 | System | System ask to enter the amount of money to transfer |
| 8 | Customer | Enter the amount of money |
| 9 | System | Check the customer balance if the funds are insufficient |
| 10 | System | Send OTP (One-Time Password) to customer |
| 11 | Customer | Enter the OTP number |
| 12 | System | System check if OTP number that Customer enter is valid or not |
| 13 | System | System ask Bank consortium to process the transfer to the destination account |
| 14 | System | System add a new transaction history |
| 15 | System | System decrease the transfer amount of the customer account |
| 16 | System | Notify successfully transfer |


6. Alternative flow of events:

| No   | Actor  | Action                                                       |
| ---- | ------ | ------------------------------------------------------------ |
| 6a.  | System | Output error: destination account is not exist, back to step enter destination bank and destination account |
| 10a. | System | Output error: Notify insufficient funds, back to step enter amount of money to transfer |
| 13a. | System | Output error: Notify OTP is not correct, back to main menu   |


7. Post-condition: The system should be ready to perform another transaction or should be in a disabled state awaiting service.