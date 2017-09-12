figure, subplot(2, 1, 1), plot(1:5, val(1:5) ./ 200);
subplot(2, 1, 2), plot(20:25, val(20:25) ./ 200);
xlabel('time (s)');
ylabel('mV');