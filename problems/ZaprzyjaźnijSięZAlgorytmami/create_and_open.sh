name=$1
dirname="${name}"
filepath="${name}/${name}.cpp"
mkdir ${dirname}
touch ${filepath}
echo "#include<iostream>" > ${filepath}
echo "using namespace std;" >> ${filepath}
echo "" >> ${filepath}
echo "int main() {" >> ${filepath}
echo "" >> ${filepath}
echo "}" >> ${filepath}
code ${dirname}
