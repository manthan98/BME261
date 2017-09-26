close all;

load('ecg-knn-data.mat');

% Feature A - raw amplitude.
featureA_QRS = ecg(peakIndices(peakLabels==1));
featureA_P = ecg(peakIndices(peakLabels==2));
featureA_T = ecg(peakIndices(peakLabels==3));

% Feature B - calculate the widths.
widths = [];
for i = 1:156
    for j = peakIndices(i):length(ecg)
        scan_right = ecg(j+1) - ecg(j);
        if scan_right > 0
            right_index = j;
            break;
        end
    end
    
    for k = peakIndices(i):-1:1
        scan_left = ecg(k-1) - ecg(k);
        if scan_left > 0
            left_index = k;
            break;
        end
    end
    
    if right_index > 0 && left_index > 0
        peak_width = right_index - left_index;
        widths = [widths peak_width];
    end
end

featureB_QRS = widths(peakLabels==1);
featureB_P = widths(peakLabels==2);
featureB_T = widths(peakLabels==3);

figure, hold on,
plot(featureA_QRS, featureB_QRS, 'rx');
plot(featureA_P, featureB_P, 'bx');
plot(featureA_T, featureB_T, 'gx');
