// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#using <System.dll>

#include<Windows.h>
#include<fstream>  //ifstream
#include<iostream>
#include<string>     //包含getline()
#include<cmath>
using namespace std;

using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;

public ref class PortChat
{
private:
	static bool _continue;
	static SerialPort^ _serialPort;

public:
	static void Main()
	{
		String^ name;
		String^ message;
		StringComparer^ stringComparer = StringComparer::OrdinalIgnoreCase;
		Thread^ readThread = gcnew Thread(gcnew ThreadStart(PortChat::Read));

		// Create a new SerialPort object with default settings.
		_serialPort = gcnew SerialPort();

		// Allow the user to set the appropriate properties.
		_serialPort->PortName = SetPortName(_serialPort->PortName);
		_serialPort->BaudRate = SetPortBaudRate(_serialPort->BaudRate);
		_serialPort->Parity = SetPortParity(_serialPort->Parity);
		_serialPort->DataBits = SetPortDataBits(_serialPort->DataBits);
		_serialPort->StopBits = SetPortStopBits(_serialPort->StopBits);
		_serialPort->Handshake = SetPortHandshake(_serialPort->Handshake);

		// Set the read/write timeouts
		_serialPort->ReadTimeout = 500;
		_serialPort->WriteTimeout = 500;

		_serialPort->Open();
		_continue = true;
		readThread->Start();

		Console::Write("Name: ");
		name = Console::ReadLine();

		Console::WriteLine("Type QUIT to exit");

		while (_continue)
		{
			string s;
			ifstream inf;
			inf.open("C://Users/admin/Desktop/比赛/Demo_for_Windows-master/Demo/abc.txt");          //特别注意，这里是：//  是双斜杠喔~~     ifstream inf("d://out.txt");用这一句可以代替这两句喔，很简单有木有~~
			while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
			{
				cout << s << endl << endl;
			}
			inf.close();
			cout << s << endl;
			String^ str2 = gcnew String(s.c_str());
			Console::WriteLine(str2);
			
			message = str2;
			Sleep(500);
			if (stringComparer->Equals("quit", message))
			{
				_continue = false;
			}
			else
			{
				_serialPort->WriteLine(
					String::Format("<{0}>: {1}", name, message));
			}
		}

		readThread->Join();
		_serialPort->Close();
	}

	static void Read()
	{
		while (_continue)
		{
			
			try
			{
				String^ message = _serialPort->ReadLine();
				Console::WriteLine(message);
			}
			catch (TimeoutException ^) {}
		}
	}

	static String^ SetPortName(String^ defaultPortName)
	{
		String^ portName;

		Console::WriteLine("Available Ports:");
		for each (String^ s in SerialPort::GetPortNames())
		{
			Console::WriteLine("   {0}", s);
		}

		Console::Write("Enter COM port value (Default: {0}): ", defaultPortName);
		portName = Console::ReadLine();

		if (portName == "")
		{
			portName = defaultPortName;
		}
		return portName;
	}

	static Int32 SetPortBaudRate(Int32 defaultPortBaudRate)
	{
		String^ baudRate;

		Console::Write("Baud Rate(default:{0}): ", defaultPortBaudRate);
		baudRate = Console::ReadLine();

		if (baudRate == "")
		{
			baudRate = defaultPortBaudRate.ToString();
		}

		return Int32::Parse(baudRate);
	}

	static Parity SetPortParity(Parity defaultPortParity)
	{
		String^ parity;

		Console::WriteLine("Available Parity options:");
		for each (String^ s in Enum::GetNames(Parity::typeid))
		{
			Console::WriteLine("   {0}", s);
		}

		Console::Write("Enter Parity value (Default: {0}):", defaultPortParity.ToString());
		parity = Console::ReadLine();

		if (parity == "")
		{
			parity = defaultPortParity.ToString();
		}

		return (Parity)Enum::Parse(Parity::typeid, parity);
	}

	static Int32 SetPortDataBits(Int32 defaultPortDataBits)
	{
		String^ dataBits;

		Console::Write("Enter DataBits value (Default: {0}): ", defaultPortDataBits);
		dataBits = Console::ReadLine();

		if (dataBits == "")
		{
			dataBits = defaultPortDataBits.ToString();
		}

		return Int32::Parse(dataBits);
	}

	static StopBits SetPortStopBits(StopBits defaultPortStopBits)
	{
		String^ stopBits;

		Console::WriteLine("Available Stop Bits options:");
		for each (String^ s in Enum::GetNames(StopBits::typeid))
		{
			Console::WriteLine("   {0}", s);
		}

		Console::Write("Enter StopBits value (None is not supported and \n" +
			"raises an ArgumentOutOfRangeException. \n (Default: {0}):", defaultPortStopBits.ToString());
		stopBits = Console::ReadLine();

		if (stopBits == "")
		{
			stopBits = defaultPortStopBits.ToString();
		}

		return (StopBits)Enum::Parse(StopBits::typeid, stopBits);
	}

	static Handshake SetPortHandshake(Handshake defaultPortHandshake)
	{
		String^ handshake;

		Console::WriteLine("Available Handshake options:");
		for each (String^ s in Enum::GetNames(Handshake::typeid))
		{
			Console::WriteLine("   {0}", s);
		}

		Console::Write("Enter Handshake value (Default: {0}):", defaultPortHandshake.ToString());
		handshake = Console::ReadLine();

		if (handshake == "")
		{
			handshake = defaultPortHandshake.ToString();
		}

		return (Handshake)Enum::Parse(Handshake::typeid, handshake);
	}
};

int main()
{
	PortChat::Main();
}
