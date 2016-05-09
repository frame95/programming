function plot_swap( M)
	fin=fopen("swap_val.txt", "r");
	y=fscanf(fin, "%d", M);
	
	hold off;
	plot(y);
	hold on;
	plot((2.^(1:M)) /2, 'r');
	
	fclose(fin);
endfunction
