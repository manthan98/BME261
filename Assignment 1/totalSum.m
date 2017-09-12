function total = totalSum( x )
% Creates a variable called 'total',
% sets it to zero, and and elements of
% x to total using a for loop.
    
    total = 0;
    for i = 1:length(x)
        elm = x(i);
        total = total + elm;
    end

end

