#creating a temporary folder for temporary files
mkdir temp
cd ./temp

#cmake with pointing at neccessary file folders
cmake -B./ -S../

#biulding the project with make
make

#getting rid of temp folder
cd ../
rm -r temp