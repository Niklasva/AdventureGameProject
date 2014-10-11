#include<Merchant.H>

void Merchant::barter()
{

  bool buy;
  bool sell;
  //Köpa eller sälja
  //Inmatning nicklas mm.

  if(buy)
    buy();
  else
    sale();
}


void sale()
{



}

void buy()
{
  //Rolig Konversation.
  
  //Detta finns att köpa

  int index{1};
  for(auto i: items_for_sale)
    {
      
      //Skriv ut item med index.
      
      ++i;
    }

  //Prata med spelaren. 
  // Spelaren väljer här index.

  int item_to_buy; 

  for(unsigned int i{0}; i < items_for_sale.size();++i)
    {
      if(item_to_buy == items_for_sale[i]);
	{


	}

    }


}
