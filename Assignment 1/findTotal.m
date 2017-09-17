function total = findTotal( x )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

    total = 0;

    for i = 1:length(x)
        elm = x(i);
        total = total + elm;
    end
    
    total

end

