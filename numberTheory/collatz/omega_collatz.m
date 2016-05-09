function omega_collatz(p) 
	cantor=zeros(1,2^p);
	omega=zeros(1,2^p);
	for n=1:2^p
		%TRADUZIONE DI n in CANTOR
		c=1; actual=0; 
		while( c<=p ) 
			temp=(mod(n,2^c)- actual)/(2^(c-1));
			cantor(n)+= 2*temp/(3^c);
			actual=mod(n,2^c);
			c++;
		endwhile
		
		%CALCOLO DI OMEGA(n)
		c=1; m=n;
		while(c <=p)
			
			if(mod(n,2) == 0) 
				n=n/2;
			else 
				n=(3*n+1)/2;
				omega(m)+=2/(3^c);
			endif
		c++;
		endwhile
	endfor
figure(1);
plot( 100*cantor, 100*(omega), 'o');
figure(2);
plot( 100*cantor, 100*(omega./cantor), 'o');
figure(3);
plot( 100*cantor, 100*(omega-cantor), 'o');			 


endfunction
