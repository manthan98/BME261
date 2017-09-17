function indices = findT( val )
% returns indices of peak locations.

    [peaks, peakLocs] = findpeaks(val, 'MinPeakWidth', 30);
    indices = peakLocs;

end

