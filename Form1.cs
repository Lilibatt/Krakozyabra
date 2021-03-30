using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.Win32;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            RegistryKey rk = Registry.CurrentUser;
            RegistryKey reskey = rk.CreateSubKey("LabKey", true);

            BackColor = Color.FromArgb(int.Parse(reskey.GetValue("Color", Color.White.ToArgb()).ToString()));
            textBox3.Text = reskey.GetValue("Text").ToString();
            Width = int.Parse(reskey.GetValue("WeightForm", 808).ToString());
            Height = int.Parse(reskey.GetValue("HeightForm", 477).ToString());

            reskey.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Width = Convert.ToInt32(textBox1.Text);
            Height = Convert.ToInt32(textBox2.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            RegistryKey rk = Registry.CurrentUser;
            RegistryKey reskey = rk.CreateSubKey("LabKey", true);
            reskey.SetValue("Color", BackColor.ToArgb());
            reskey.SetValue("Text", textBox3.Text);
            reskey.SetValue("WeightForm", Size.Width);
            reskey.SetValue("HeightForm", Size.Height);
            reskey.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            BackColor = Color.Black;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            BackColor = Color.Red;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            BackColor = Color.Yellow;
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            string c = "Лучше быть последним — первым, чем первым — последним.";
            MessageBox.Show(c, "Приколюхи", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            string c = "Не бывает безвыходных ситуаций. Бывают ситуации, выход из которых тебя не устраивает.";
            MessageBox.Show(c, "Приколюхи", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            string c = "Семейное положение: нет даже кота.";
            MessageBox.Show(c, "Приколюхи", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            BackColor = Color.White;
        }
    }
}
