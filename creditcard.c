#include <cs50.h>
#include <stdio.h>

int card_len(long cardN);
int even2(long cardN);
int odd3(long cardN);
bool amex(long cardN);
bool visa(long cardN);
bool master(long cardN);

int main(void)

{
    long long cardNum;
    do
    {
        cardNum = get_long("Card Number: ");
    }
    while (cardNum<= 0);



    int x;
    x = (odd3(cardNum) + even2(cardNum));
     while(x>=10){
        x/=10;
    }
    int d[2];
    for (int i=0; i<2; i++){
        d[i] = x%10;
        x/=10;
    }
    if (d[1]==0 && card_len(cardNum) == 16 && master(cardNum))
         printf("MASTERCARD\n");
    else if (d[1] == 0 && (card_len(cardNum) == 16 || card_len(cardNum) == 13 )&& visa(cardNum))
        printf("VISA\n");
    else if (d[1] == 0 && card_len(cardNum) == 15 && amex(cardNum))
        printf("AMEX\n");

    else
        printf("INVALID\n");



// commeting out old/uesless codes as a note and reminder to myself
        // if (odd3(cardNum) + even2(cardNum) == 20 && card_len(cardNum) == 13  && visa(cardNum)) //13 digit card
        //     printf("VISA\n");
        // else if (odd3(cardNum) + even2(cardNum) == 20 && card_len(cardNum) == 15 && amex(cardNum))//15 digit card
        //     printf("AMEX\n");
        // else if (odd3(cardNum) + even2(cardNum) == 20 && card_len(cardNum) == 16 && visa(cardNum))//16 digit card
        //     printf("VISA\n");
        // else if (odd3(cardNum) + even2(cardNum) == 20 && card_len(cardNum) == 16 && master(cardNum))//16 digit card
        //     printf("MASTERCARD\n");
        // else
        //     printf("INVALID\n");

    // if(master(cardNum))
    //     printf("It's True\n");
    // else
    //     printf("Invalid\n");
}


int card_len(long cardN){

    int length = 0;
    while(cardN!=0){
        cardN=cardN/10;
        length++;

    }
    if (length==13)

        return 13;

    else if (length==15)

        return 15;
    else if (length == 16)

        return 16;
    else
        return false;
}


// from [0] starting from the back
int even2(long cardN){

    int c;
    int digits[8];               // storage for odd digits
    int i;
    for (i = 0; i < 8; ++i)  // for each odd digit

    {
    digits[i] = cardN %10; // extract the digit
    cardN /= 100;          // throw away two digits
    }

    c = digits[0] + digits[1] + digits[2] + digits[3] + digits[4] + digits[5] + digits[6] + digits[7];
    return c;
}

// commeting out old/uesless codes as a note and reminder to myself
//13 from [1]
// int odd1(long cardN){

//     int digits[6];               // storage for odd digits
//     int i;
//     int c;
//     cardN/=10;
//     for (i = 0; i < 6; ++i)  // for each odd digit
//     {
//     digits[i] = cardN %10; // extract the digit
//     cardN /= 100;          // throw away two digits
//     }

//     c = digits[0]*2 + digits[1]*2+ digits[2]*2 + digits[3]*2 + digits[4]*2+ digits[5]*2;
//     return c;
// }
//15 from [1]
// int odd2(long cardN){
//     int c;
//     int digits[7];               // storage for odd digits
//     int i;

//     cardN/=10;
//     for (i = 0; i < 7; ++i)  // for each odd digit
//     {
//     digits[i] = cardN %10; // extract the digit
//     cardN /= 100;          // throw away two digits
//     }

//     c = digits[0]*2 + digits[1]*2 + digits[2] * 2 + digits[3]*2 + digits[4]*2 + digits[5]* 2 + digits[6]*2;
//     return c;

// }

//from[1]starting from the back
int odd3(long cardN){

    int digits[8];               // storage for odd digits
    int i;
    int total;
    cardN/=10;
    for (i = 0; i < 8; ++i)  // for each odd digit
    {
    digits[i] = cardN %10; // extract the digit
    cardN /= 100;          // throw away two digits
    }
    int digLen;
    digLen = sizeof(digits)/sizeof(digits[0]); // get length of digits[]
    for(i=0; i<digLen; i++) digits[i]*=2; // multiply each digits[] in array by 2

    int d0[2];
    for (i=0; i<2; i++){
        d0[i] = digits[0]%10;
        digits[0]/=10;
    }

    int d1[2];
    for (i=0; i<2; i++){
        d1[i] = digits[1]%10;
        digits[1]/=10;
    }

    int d2[2];
    for (i=0; i<2; i++){
        d2[i] = digits[2]%10;
        digits[2]/=10;
    }

    int d3[2];
    for (i=0; i<2; i++){
        d3[i] = digits[3]%10;
        digits[3]/=10;
    }

    int d4[2];
    for (i=0; i<2; i++){
        d4[i] = digits[4]%10;
        digits[4]/=10;
    }


    int d5[2];
    for (i=0; i<2; i++){
        d5[i] = digits[5]%10;
        digits[5]/=10;
    }

    int d6[2];
    for (i=0; i<2; i++){
        d6[i] = digits[6]%10;
        digits[6]/=10;
    }

    int d7[2];
    for (i=0; i<2; i++){
        d7[i] = digits[7]%10;
        digits[7]/=10;
    }


    total = d0[0] + d0[1]+ d1[0] + d1[1] + d2[0] + d2[1]+ d3[0] + d3[1] + d4[0]+ d4[1]+ d5[0] + d5[1]  + d6[0] + d6[1] + d7[0] + d7[1];
    return total;

}


bool amex(long cardN){

    while (cardN >= 100)
    {
        cardN /= 10;
    }


    if (cardN == 34)
        return true;
    else if (cardN == 37)
        return true;
    else
        return false;

}

bool visa(long cardN){
    while(cardN>=10){
        cardN/=10;
    }
    if (cardN == 4)
        return true;
    else
        return false;
}

bool master(long cardN){
    while(cardN>=100){
        cardN/=10;
    }

   if (cardN >= 51 && cardN <= 55)
        return true;
    else
        return false;
}
