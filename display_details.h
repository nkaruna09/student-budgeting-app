 /* 
 * This header file defines functions related to display_details, including operations such as:
 * - displaying account type.
 * - displaying account balance.
 * - displaying personal information
 */

#ifndef DISPLAY_DETAILS_H
#define DISPLAY_DETAILS_H

//display account type
void display_account_type(const char *account_type);

//display account balance
void display_account_balance(double balance);

//display personal info
void display_personal_info(const char *name, const char *card_number);

#endif