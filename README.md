# NupicModule
Brain Simulator module based on the NuPIC platform.

To start to use the NupicModule you have to:
- have the Brain Simulator installed
- clone the NupicModule repository (or download and unpack the zip with sources)
- create the project file NupicModule.csproj.user in the folder NupicModule\Module for the NupicModule project; this can be created from the NupicModule.csproj.user.template-RENAME_ME file by removing the postfix in its name
- open the NupicModule\NupicModule.sln in MS VisualStudio 2013 and edit the paths in NupicModule project's Properties/Debug tab so they point to your Brain Simulator installation and to your location of the NupicModule
- now hitting StartDebugging (F5) should build everything, launch the installed Brain Simulator and load the NupicModule.dll into it


The example file is located in the BrainSimulatorExample\CLA_mnist_prediction.brain. You can find the description of the example project in the Brain Simulator documentation in the section Examples/Nupic Node.