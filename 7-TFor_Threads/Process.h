//template <class Op>
class Process
{
private:
	int weightProcess;
public:
	Process(int weight){
		weightProcess = weight;
	}
	int getWeight(){
		return weightProcess;
	}
};