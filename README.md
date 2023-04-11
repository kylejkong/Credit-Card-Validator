# Credit-Card-Validator
c, credit card validation, 

### You will need to install cs50 library and hav #include <cs50.h>  in your main file to run this program ####


It uses The Luhn Algorithm—also known as the “Modulus 10 Algorithm” to validate a credit card. 



First, it requests a credit card number from user.  (long is a custom function made by cs50 for handling long integers)If 
it is not an input of positive integers , program will reprompt user to enter again.

Based on the length of the card ( 15 for Amex, 16 for either MasterCard or Visa, or 13 for for Visa) and its starting numbers (34 or 37 for Amex, from 51 to 55 for MasterCard and 4 for Visa) and having passed the custom made Modulus 10 Algorithm , it will then determine the user's input is a Visa, Amex , MasterCard or an invalid card. 
