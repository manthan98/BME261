function indices = findT( val )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

    [peaks, peakLocs] = findpeaks(val, 'MinPeakWidth', 30);
    indices = peakLocs

end

