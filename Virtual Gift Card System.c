#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int acc_lim=0;
int card_lim=0;
int tran_lim=0;
int pin_val=1000;
int top_up();
int cus_print();
int create();
int gift();
int close();
int giftcard();
int purchase();
int gift_print();
int tran_print();
struct bank
{
    int balance;
}cus[100];
struct gift_card
{
    int cus_id;
    int pin;
    int gift_card_bal;
    int status;
}card[100];
struct tran{
    int cardno;
    int amount;
}t[100];
int main()
{
    int choice;
    while(1)
    {
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SBI - STATE BANK OF INDIA \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t1.Create Bank Account\n\t\t\t2.Bank Account Summary\n\t\t\t3.Virtual Gift Card Management\n\t\t\t4.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            create();
            break;
        }
   case 2:
        {
            cus_print();
            break;
        }
    case 3:
        {
            gift();
            break;
        }
    case 4:
        {
            exit(1);
            break;
        }
    }
    printf("\n\n================================================================================\n\n");
    }

}
int create()
{
    int bal;
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ACCOUNT CREATION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\tEnter the initial balance----->");
    scanf("%d",&bal);
    if(bal>0)
    {
        acc_lim++;
        cus[acc_lim].balance=bal;
        printf("\t\tAccount Successfully created :) :)\n\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t|    CUS-ID   |       BALANCE         |\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t|    %d       |        %d           |\n",acc_lim,cus[acc_lim].balance);
        printf("\t\t--------------------------------------\n");
        return 1;
    }else
    {
        printf("\t\tAccount Balance cannot be nil\n\n");
        return 0;
    }
}
int cus_print()
{
    int i;
    if(acc_lim>0)
    {
        printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BANK ACCOUNT SUMMARY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\t\t--------------------------------------\n");
        printf("\t\t|    CUS-ID   |       BALANCE         |\n");
        printf("\t\t--------------------------------------\n");
        for(i=1;i<=acc_lim;i++)
        {
        printf("\t\t|    %d        |        %d            |\n",i,cus[i].balance);
        }
        printf("\t\t--------------------------------------\n");
        return 1;
    }
    else{
        printf("\t\t Account Summary NIL \n\n");
        return 0;
    }
}
int gift()
{
    int ch;
    while(1)
    {
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VIRTUAL GIFT CARD MANAGEMENT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
     printf("\t\t\t1.Create Gift Card\n\t\t\t2.Top-up gift card\n\t\t\t3.Close a Gift Card\n\t\t\t4.Purchase item\n\t\t\t5.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            giftcard();
            break;
        }
    case 2:
        {
            top_up();
            break;
        }
   case 3:
        {
            close();
            break;
        }
   case 4:
        {
            purchase();
            break;
        }
    case 5:
        {
            return 1;
            break;
        }
    }
    }
}
int giftcard()
{
    int id,bal;
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2GIFT CARD\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\tEnter your bank customer-id----> ");
    scanf("%d",&id);
    if((id>0)&&(id<=acc_lim))
    {
        printf("\t\tEnter the Gift Card Balance ---->");
        scanf("%d",&bal);
        if(bal<cus[id].balance)
        {
        card_lim++;
        card[card_lim].cus_id=id;
        card[card_lim].pin=pin_val+card_lim;
        card[card_lim].status=1;
        card[card_lim].gift_card_bal=bal;
        cus[id].balance-=bal;
        gift_print();
        cus_print();
        return 1;
        }
        else{
            printf("\n\t\t Insufficient Balance in Account :( :( \n\n");
            return 0;
        }
    }
    else{
        printf("\n\t\t Account not found :( :( \n\t\t\t Create a bank account\n");
        create();
        giftcard();
    }
}
int gift_print()
{
    int i;
    char sta[7];
    if(card_lim>0)
    {
        printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GIFT CARD SUMMARY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\t---------------------------------------------------\n");
        printf("\t| CARD NO | CUS-ID |  PIN  |  STATUS  |   BALANCE  |\n");
        printf("\t---------------------------------------------------\n");
        for(i=1;i<=card_lim;i++)
        {
            if(card[i].status==1)
            {
                strcpy(sta,"Active");
            }
            else
            {
                strcpy(sta,"Closed");
            }
        printf("\t|   %d    |   %d   |   %d  | %s   |   %d     |\n",i,card[i].cus_id,card[i].pin,sta,card[i].gift_card_bal);
        }
        printf("\t---------------------------------------------------\n");
        return 1;
    }
    else{
        printf("\t\t Gift Card is NIL\n\n");
        return 0;
    }
}
int top_up()
{
    int id,amt,k;
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TOP_UP AMOUNT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\tEnter your card id ---->");
    scanf("%d",&id);
    if((id>0)&&(id<=card_lim))
    {
        k=card[id].cus_id;
        printf("\t\tEnter the top-up amount ----> ");
        scanf("%d",&amt);
        if(amt<cus[k].balance)
        {
            cus[k].balance-=amt;
            card[id].gift_card_bal+=amt;
            gift_print();
            cus_print();
            return 1;
        }
        else{
            printf("\t\tInsufficient Balance in Account :( :( \n\n");
            return 0;
        }
    }
    else
    {
        printf("\t\t Card id not available :( :( \n\n\t\tCreate a Gift Card \n\n");
        giftcard();
        top_up();
    }
}
int close()
{
    int id,pin_no,bal,k;
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CLOSE ACCOUNT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\tEnter your card id --->");
    scanf("%d",&id);
    if((id>0)&&(id<=card_lim))
    {
        printf("\t\tEnter your PIN no ---> ");
        scanf("%d",&pin_no);
        if(card[id].pin==pin_no)
        {
            k=card[id].cus_id;
            card[id].status=0;
            bal=card[id].gift_card_bal;
            card[id].gift_card_bal=0;
            cus[k].balance+=bal;
            cus_print();
            gift_print();
            return 1;
        }
        else{
            printf("\t\t Invalid PIN no :( :(\n\n");
            return 0;
        }
    }
    else
    {
        printf("\t\tGift Card does not exists :( :(\n\n");
        return 0;
    }
}
int purchase()
{
    int id,pinno,amt,k;
    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TOP_UP AMOUNT \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\tEnter your card id ---->");
    scanf("%d",&id);
    if((id>0)&&(id<=card_lim))
    {
        printf("\t\tEnter your PIN no ---> ");
        scanf("%d",&pinno);
        if(card[id].pin==pinno)
        {
        k=card[id].cus_id;
        printf("\t\tEnter the purchase amount ----> ");
        scanf("%d",&amt);
        if(amt<cus[k].balance)
        {
            tran_lim++;
            t[tran_lim].cardno=id;
            t[tran_lim].amount=amt;
            cus[k].balance-=amt;
            card[id].gift_card_bal+=amt;
            tran_print();
            gift_print();
            cus_print();
            return 1;
        }
        else{
            printf("\t\tInsufficient Balance in Account :( :( \n\n");
            return 0;
        }
        }
        else{
            printf("\t\t Invalid PIN no :( :(\n\n");
            return 0;
        }
    }
    else
    {
        printf("\t\t Card id not available :( :( \n\n\t\tCreate a Gift Card \n\n");
        giftcard();
        purchase();
    }

}
int tran_print()
{
    int i;
    if(tran_lim>0)
    {
        printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 TRANSACTION SUMMARY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\t-------------------------------------------\n");
        printf("\t|  TXN NO  |  CARD NO   |      BALANCE     |\n");
        printf("\t-------------------------------------------\n");
        for(i=1;i<=tran_lim;i++)
        {
        printf("\t|    %d    |    %d      |     %d        |\n",i,t[i].cardno,t[i].amount);
        }
        printf("\t-------------------------------------------\n");
        return 1;
    }
    else{
        printf("\t\t Transaction Summary NIL \n\n");
        return 0;
    }

}
