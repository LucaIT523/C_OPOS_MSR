using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AxOposMSR_CCO;
using OposMSR_CCO;
using System.Windows.Forms;
using System.ComponentModel;


namespace C_SHARP_TEST
{
    internal class Program
    {
        static public AxOPOSMSR axOPOSMSR1;

        static public void axOPOSMSR1_DataEvent(object sender, _IOPOSMSREvents_DataEventEvent e)
        {
            try
            {
                Console.WriteLine("Start ... axOPOSMSR1_DataEvent");

                axOPOSMSR1.DeviceEnabled = false;
                axOPOSMSR1.DataEventEnabled = false;

                bool flag = axOPOSMSR1.Track2Data.Trim().Length > 0;
                if (flag)
                {
                    Console.WriteLine("OK ... axOPOSMSR1.Track2Data");
                    string text = axOPOSMSR1.Track2Data;
                    Console.WriteLine(text);
                }
                else
                {
                    bool flag3 = axOPOSMSR1.Track1Data.Trim().Length > 0;
                    if (flag3)
                    {
                        Console.WriteLine("OK ... axOPOSMSR1.Track1Data");
                        string text2 = axOPOSMSR1.Track1Data;
                        Console.WriteLine(text2);
                    }
                }

                Console.WriteLine("End ... axOPOSMSR1_DataEvent");
                axOPOSMSR1.DeviceEnabled = true;
                axOPOSMSR1.DataEventEnabled = true;
            }
            catch (Exception ex)
            {
                Console.WriteLine("error ... catch axOPOSMSR1_DataEvent");
            }
            finally
            {
                axOPOSMSR1.DeviceEnabled = true;
                axOPOSMSR1.DataEventEnabled = true;
            }
        }

        static public int prcStartMSR()
        {
            int w_nRtn = -1;
            try
            {
                w_nRtn = axOPOSMSR1.Open("NCRMSR.0");
                if (w_nRtn == 0)
                {
                    Console.WriteLine("OK ... open NCRMSR");

                    axOPOSMSR1.ClaimDevice(0);
                    axOPOSMSR1.TracksToRead = 3;

                    if (axOPOSMSR1.ResultCode == 0)
                    {
                        axOPOSMSR1.DeviceEnabled = true;
                        axOPOSMSR1.DataEventEnabled = true;
                        axOPOSMSR1.AutoDisable = false;

                        Console.WriteLine("OK ... prcStartMSR end");

                        return 0;
                    }
                    else
                    {
                        Console.WriteLine("Faild ... prcStartMSR setting");
                        return -1;
                    }
                }
                else
                {
                    Console.WriteLine("Faild ... open NCRMSR");
                    return -1;
                }

            }
            catch
            {
                Console.WriteLine("error ... catch prcStartMSR");
                return -1;
            }
        }

        static public void prcCloseMSR()
        {
            try
            {
                Console.WriteLine("Start ... prcCloseMSR");

                bool deviceEnabled = axOPOSMSR1.DeviceEnabled;
                if (deviceEnabled)
                {
                    axOPOSMSR1.DeviceEnabled = false;
                }
                bool dataEventEnabled = axOPOSMSR1.DataEventEnabled;
                if (dataEventEnabled)
                {
                    axOPOSMSR1.DataEventEnabled = false;
                }
                axOPOSMSR1.ReleaseDevice();
                axOPOSMSR1.Close();
                Console.WriteLine("End ... prcCloseMSR");
            }
            catch
            {
                Console.WriteLine("error ... catch prcCloseMSR");
            }
        }

        [STAThread]
        static void Main(string[] args)
        {
            int w_nSts = -1;

            Console.WriteLine("Starting .... ");

            axOPOSMSR1 = new AxOPOSMSR();

            axOPOSMSR1.Enabled = true;
            //axOPOSMSR1.Location = new Point(41, 46);
            axOPOSMSR1.Name = "axOPOSMSR1";
            //axOPOSMSR1.OcxState = (AxHost.State)componentResourceManager.GetObject("axOPOSMSR1.OcxState");
            //axOPOSMSR1.Size = new Size(240, 240);
            axOPOSMSR1.TabIndex = 1;
            axOPOSMSR1.DataEvent += axOPOSMSR1_DataEvent;

            if (prcStartMSR() == 0)
            {
                // Keep the application running until a key is pressed
                Console.WriteLine("Press input a card on the device.");
                Console.ReadKey();

                prcCloseMSR();
            }
        }
    }
}
