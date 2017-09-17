time_to_five = 1/360:1/360:5;
signal_to_five = val(1:(5*360)) / 200;
subplot(2, 1, 1), plot(time_to_five, signal_to_five);
xlabel('time (s)');
ylabel('mV');

time_to_twentyFive = 20/360:1/360:25;
signal_to_twentyFive = val(20:(25*360)) / 200;
subplot(2, 1, 2), plot(time_to_twentyFive, signal_to_twentyFive);
xlabel('time (s)');
ylabel('mV');