#include "SedProcessor.hpp"

bool SedProcessor::processFile(const std::string& filename) const {
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cout << "Erreur: Impossible d'ouvrir le fichier " << filename << std::endl;
		return false;
	}
	//std::string content;
	//std::string line;
	//bool firstLine = true;
	//while (std::getline(inputFile, line)) {
    //	if (!firstLine) content += "\n";  // Ajouter \n avant chaque ligne sauf la première
    //	content += line ;
    //	firstLine = false;
	//}
	std::string content((std::istreambuf_iterator<char>(inputFile)),
                    std::istreambuf_iterator<char>());
	inputFile.close();
	std::string modifiedContent = replaceString(content);
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile) {
		std::cout << "Erreur lors de l'ouverture du fichier de sortie" << std::endl;
		return false;
	}
	outputFile << modifiedContent;
	outputFile.close();
	std::cout << "Fichier lu avec succes" << std::endl;
	return true;
}
