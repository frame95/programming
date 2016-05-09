function r=distinctprimes(n)
	m=2^n+1;
	nprimes=zeros(m,1)+1;
	for i=2:m
		if(nprimes(i) == 1) 
			i
			j=2;
			while (j <= m/i)
				nprimes(i*j)=nprimes(i*j)+1;
				j++;
			endwhile
		endif
	endfor
	x=1:n;
	plot(x, nprimes(2.^x+1), 'r' );
	hold on;
	plot(x, log(x) , 'b');
endfunction
		

