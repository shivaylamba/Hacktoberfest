#-------------------------
# importing Libraries
#-------------------------

using DataFrames
using Flux
using Flux: crossentropy
using Flux: @epochs
using Flux: argmax
using CSV
using LinearAlgebra
println("importing Libraries Completed")
#--------------------------
# Loading Data
#--------------------------

MNIST_Train = CSV.read("digit-recognizer/train.csv")  ### TRAIN DATA
MNIST_Test  = CSV.read("digit-recognizer/test.csv"); ### TEST DATA
println("importing Data Completed")

#--------------------------
# Extracting Feature and Label
#--------------------------

Feature = MNIST_Train[:,2:785]
Label   = MNIST_Train[:,1]
Test    = MNIST_Test
println("feature label array made")

#--------------------------
# Distributing Data into TRAIN DEV and TEST set.
#--------------------------

size_of_feature, feature_count = size(Feature)
distribution_perc = 0.8 ## 80%
size_of_train_data = convert(Int64, size_of_feature * distribution_perc)

x_train = Feature[1:size_of_train_data,:]
y_train = Label[1:size_of_train_data]
X_dev   = Feature[size_of_train_data:size_of_feature,:]
y_dev   = Label[size_of_train_data:size_of_feature]
println("distribution completed")

#--------------------------
# One Hot Encoding Of Label
#--------------------------

function one_hot_encoding(label)
	n_size = size(label)[1]
	label_arr = fill(0,( n_size, 10))
	for y in 1:n_size
		label_arr[y,label[y]+1] = 1
	end
	return label_arr
end

#--------------------------
# Function for Reshaping Feature to Image ((,784) => ( ,28, 28, 1 ,1))
#--------------------------

function reshaping(features)
	n_row, n_col = size(features)
	image_arr = fill(0.0,( n_row,28, 28, 1)) ### EMPTY ARRAY OF SIZE (33600, 28 ,28 1) AND (8401, 28, 28, 1)

    for index in 1:n_row
       image_arr[index,:,:,:] = reshape(convert(Array, features[index,:]), 28, 28, 1)/255## RESHAPING AND NORMALIZING BY DIVIDING BY 255\
    end

    return reshape(image_arr, (28,28,1,n_row))
end
#--------------------------
# OHE of Labels
#--------------------------

train_label = one_hot_encoding(y_train)
dev_label   = one_hot_encoding(y_dev)
println("label Encoded")
println(size(train_label))
#--------------------------
# Reshaphing The Data.
#--------------------------

train_image = reshaping(x_train)
dev_image   = reshaping(X_dev)
test_image  = reshaping(Test)
println("reshaping Done")

traindata = []
push!(traindata,(train_image,train_label))
println(size(traindata))
#--------------------------
# MODEL
#--------------------------


model = Chain(
    Conv((2,2), 1=>16, relu),
    x -> maxpool(x, (2,2)),
    Conv((2,2), 16=>8, relu),
    x -> maxpool(x, (2,2)),
    x -> reshape(x, :, size(x, 4)),
    Dense(288, 10),
    softmax)


loss(x, y) = crossentropy(model(x), y)
opt = ADAM(params(model))

@epochs 13 Flux.train!(loss, traindata, opt)

predicted = model(reshape(Float64.(dev_image), (28, 28, 1, size(dev_image)[1])))

accuracy = mean(argmax(predicted)-1 .== test_y)
println(accuracy)
