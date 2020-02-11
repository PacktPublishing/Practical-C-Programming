#include <stdio.h>
#define Qty 10
#define FestivalOffer 2 
#define DiscountCoupon 5
#define Kindle 2  
	
int main()
{
	int discount;
	float price, totalAmount, afterDisc, afterFDisc;

	printf("Enter price of a book ");
	scanf("%f", &price);
	#if Qty >= 10
		discount=15;
	#elif Qty >=5
		discount=10;
	#else
		discount=5;
	#endif
	totalAmount=Qty*price;
	afterDisc=totalAmount - (totalAmount*discount)/100;
	#ifdef FestivalOffer
		afterFDisc=afterDisc-(totalAmount*FestivalOffer)/100;
	#else
		afterFDisc=afterDisc;
	#endif
	

	printf("Quantity = %d, Price is $ %.2f, total amount for the books is $ %.2f\n", Qty, price, totalAmount);
	printf("Discount is %d%% and the total amount after discount is $ %.2f\n", discount, afterDisc);
	#ifdef FestivalOffer
		printf("Festival discount is %d%%, the total amount after festival discount is $ %.2f\n", FestivalOffer, afterFDisc);
	#endif
	#if defined (DiscountCoupon)
   		printf("You are also eligible for a discount coupon of $ %d\n", DiscountCoupon);
	#endif
	#ifndef Kindle
		#define Kindle 1
	#endif
	printf("You can use the Kindle version of the book for %d month(s)\n", Kindle);
	return 0;
}