% 0 to 5 sec.
time_to_five = linspace(1, 5, 1800);
signal_to_five = val(1:(5*360)) / 200;
figure, subplot(2, 1, 1), plot(time_to_five, signal_to_five);
indices_to_five = findT(signal_to_five);
hold on, plot(time_to_five(indices_to_five), signal_to_five(indices_to_five), 'rx');
xlabel('time (s)');
ylabel('mV');

% 20 to 25 sec.
time_to_twentyFive = linspace(20, 25, 1801);
signal_to_twentyFive = val((20*360):(25*360)) / 200;
subplot(2, 1, 2), plot(time_to_twentyFive, signal_to_twentyFive);
indices_to_twentyFive = findT(signal_to_twentyFive);
hold on, plot(time_to_twentyFive(indices_to_twentyFive), signal_to_twentyFive(indices_to_twentyFive), 'rx');
xlabel('time (s)');
ylabel('mV');