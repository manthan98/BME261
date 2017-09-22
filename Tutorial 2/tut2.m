close all;
load fisheriris;

% Question 1.
% Part A.
X = meas
Y = species

% Part B.
Y{1}
classes = unique(Y)

% Part C.
figure, plot3(X(1:3, 1), X(1:3, 2), X(1:3, 3), 'rx');

% Part D.
figure,
subplot(3, 1, 1), plot3(X(strcmp(species, 'setosa'), 1), X(strcmp(species, 'setosa'), 2), X(strcmp(species, 'setosa'), 3), 'rx');
subplot(3, 1, 2), plot3(X(strcmp(species, 'versicolor'), 1), X(strcmp(species, 'versicolor'), 2), X(strcmp(species, 'versicolor'), 3), 'gx');
subplot(3, 1, 3), plot3(X(strcmp(species, 'virginica'), 1), X(strcmp(species, 'virginica'), 2), X(strcmp(species, 'virginica'), 3), 'bx');
xlabel('Sepal Length');
ylabel('Sepal Width');
zlabel('Petal Length');

% Question 2.
% Standardize, calculates the mean of each axis and centers, and rest are 
% based on standard deviation.

% Part A.
model = fitcknn(X, Y, 'NumNeighbors', 5, 'Standardize', 1);

% Part B.
avg_flower = [mean(X(:, 1)), mean(X(:, 2)), mean(X(:, 3)), mean(X(:, 4))];
predict(model, avg_flower); % versicolor.

% Part C.
valid_ind = 5:5:length(Y);
train_ind = setdiff(1:length(Y), valid_ind);
model_subset = fitcknn(X(train_ind, :), Y(train_ind), 'NumNeighbors', 5, 'Standardize', 1);

errors = 0;
for i = 1:length(valid_ind)
    prediction = predict(model_subset, X(valid_ind(i), :));
    actual = Y(valid_ind(i));
    if strcmp(prediction, actual) == 0
        errors = errors + 1;
    end
end
