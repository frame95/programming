function r=plotord(data)
	n=size(data,1);	
	hold on;
	for i=1:n
		if( data(i,1)-1 == 3*data(i,2) )
			plot(data(i,1),data(i,2) );
		endif
	endfor
endfunction
