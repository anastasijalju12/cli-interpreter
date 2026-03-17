#include "Batch.h"
#include "CommandType.h"
Batch::Batch(string commandLine) :VariableArgument(commandLine) {
	output = "";
	controlledLoading();
	process();
}

void Batch::controlledLoading() {
	processArgument(argument);
	processDeterminedRedirectionVariableArgument(argument, output);
}

void Batch::process() {
	stringstream streamTemp;
	(streamTemp).str(this->argument);
	string line;
	while (getline(streamTemp, line)) {
		if (line.size() > 512) {
			line = line.substr(0, 512);
		}

		string realOutput;
		if (output == "")realOutput = "";
		else if (line.find('>') != string::npos)realOutput = "";
		else realOutput = " >" + output;

		CommandType* command_type = new CommandType(line+realOutput);
		command_type->objectMaking();
	}
}

void Batch::processDeterminedRedirectionVariableArgument(string& argument, string& output)
{
	if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::NONE) {
		processRedirection(argument, output);
	}
	else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::START) {
		throw GBatchPogresnoUCevovodu();
	}
	else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::MIDDLE) {
		throw GBatchPogresnoUCevovodu();
	}
	else if (PipelineStatus::getInstance().getPipePosition() == PipelineStatus::PipePosition::END) {
		processRedirectionOnlyOutput(output);
	}
}
