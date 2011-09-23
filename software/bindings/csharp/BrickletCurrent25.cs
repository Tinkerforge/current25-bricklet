/*************************************************************
 * This file was automatically generated on 2011-09-20.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

namespace Tinkerforge
{
	public class BrickletCurrent25 : Device 
	{
		private static byte TYPE_GET_CURRENT = 1;
		private static byte TYPE_CALIBRATE = 2;
		private static byte TYPE_IS_OVER_CURRENT = 3;
		private static byte TYPE_GET_ANALOG_VALUE = 4;
		private static byte TYPE_SET_CURRENT_CALLBACK_PERIOD = 5;
		private static byte TYPE_GET_CURRENT_CALLBACK_PERIOD = 6;
		private static byte TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD = 7;
		private static byte TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD = 8;
		private static byte TYPE_SET_CURRENT_CALLBACK_THRESHOLD = 9;
		private static byte TYPE_GET_CURRENT_CALLBACK_THRESHOLD = 10;
		private static byte TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD = 11;
		private static byte TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD = 12;
		private static byte TYPE_SET_DEBOUNCE_PERIOD = 13;
		private static byte TYPE_GET_DEBOUNCE_PERIOD = 14;
		private static byte TYPE_CURRENT = 15;
		private static byte TYPE_ANALOG_VALUE = 16;
		private static byte TYPE_CURRENT_REACHED = 17;
		private static byte TYPE_ANALOG_VALUE_REACHED = 18;
		private static byte TYPE_OVER_CURRENT = 19;

		public delegate void Current(short current);
		public delegate void AnalogValue(ushort value);
		public delegate void CurrentReached(short current);
		public delegate void AnalogValueReached(ushort value);
		public delegate void OverCurrent();

		public BrickletCurrent25(string uid) : base(uid) 
		{
			messageCallbacks[TYPE_CURRENT] = new MessageCallback(CallbackCurrent);
			messageCallbacks[TYPE_ANALOG_VALUE] = new MessageCallback(CallbackAnalogValue);
			messageCallbacks[TYPE_CURRENT_REACHED] = new MessageCallback(CallbackCurrentReached);
			messageCallbacks[TYPE_ANALOG_VALUE_REACHED] = new MessageCallback(CallbackAnalogValueReached);
			messageCallbacks[TYPE_OVER_CURRENT] = new MessageCallback(CallbackOverCurrent);
		}

		public void GetCurrent(out short current)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_CURRENT, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_CURRENT, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetCurrent in time");
			}

			current = LEConverter.ShortFrom(4, answer);

			writeEvent.Set();
		}

		public void Calibrate()
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_CALIBRATE, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_CALIBRATE, false);
		}

		public void IsOverCurrent(out bool over)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_IS_OVER_CURRENT, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_IS_OVER_CURRENT, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for IsOverCurrent in time");
			}

			over = LEConverter.BoolFrom(4, answer);

			writeEvent.Set();
		}

		public void GetAnalogValue(out ushort value)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_ANALOG_VALUE, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_ANALOG_VALUE, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetAnalogValue in time");
			}

			value = LEConverter.UShortFrom(4, answer);

			writeEvent.Set();
		}

		public void SetCurrentCallbackPeriod(uint period)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_CURRENT_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(period, 4, data);

			ipcon.Write(this, data, TYPE_SET_CURRENT_CALLBACK_PERIOD, false);
		}

		public void GetCurrentCallbackPeriod(out uint period)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_CURRENT_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_CURRENT_CALLBACK_PERIOD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetCurrentCallbackPeriod in time");
			}

			period = LEConverter.UIntFrom(4, answer);

			writeEvent.Set();
		}

		public void SetAnalogValueCallbackPeriod(uint period)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(period, 4, data);

			ipcon.Write(this, data, TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD, false);
		}

		public void GetAnalogValueCallbackPeriod(out uint period)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetAnalogValueCallbackPeriod in time");
			}

			period = LEConverter.UIntFrom(4, answer);

			writeEvent.Set();
		}

		public void SetCurrentCallbackThreshold(char option, short min, short max)
		{
			byte[] data = new byte[9];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_CURRENT_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)9, 2, data);
			LEConverter.To(option, 4, data);
			LEConverter.To(min, 5, data);
			LEConverter.To(max, 7, data);

			ipcon.Write(this, data, TYPE_SET_CURRENT_CALLBACK_THRESHOLD, false);
		}

		public void GetCurrentCallbackThreshold(out char option, out short min, out short max)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_CURRENT_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_CURRENT_CALLBACK_THRESHOLD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetCurrentCallbackThreshold in time");
			}

			option = LEConverter.CharFrom(4, answer);
			min = LEConverter.ShortFrom(5, answer);
			max = LEConverter.ShortFrom(7, answer);

			writeEvent.Set();
		}

		public void SetAnalogValueCallbackThreshold(char option, ushort min, ushort max)
		{
			byte[] data = new byte[9];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)9, 2, data);
			LEConverter.To(option, 4, data);
			LEConverter.To(min, 5, data);
			LEConverter.To(max, 7, data);

			ipcon.Write(this, data, TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, false);
		}

		public void GetAnalogValueCallbackThreshold(out char option, out ushort min, out ushort max)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetAnalogValueCallbackThreshold in time");
			}

			option = LEConverter.CharFrom(4, answer);
			min = LEConverter.UShortFrom(5, answer);
			max = LEConverter.UShortFrom(7, answer);

			writeEvent.Set();
		}

		public void SetDebouncePeriod(uint debounce)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_DEBOUNCE_PERIOD, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(debounce, 4, data);

			ipcon.Write(this, data, TYPE_SET_DEBOUNCE_PERIOD, false);
		}

		public void GetDebouncePeriod(out uint debounce)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_DEBOUNCE_PERIOD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_DEBOUNCE_PERIOD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetDebouncePeriod in time");
			}

			debounce = LEConverter.UIntFrom(4, answer);

			writeEvent.Set();
		}

		public int CallbackCurrent(byte[] data)
		{
			short current = LEConverter.ShortFrom(4, data);

			((Current)callbacks[TYPE_CURRENT])(current);
			return 6;
		}

		public int CallbackAnalogValue(byte[] data)
		{
			ushort value = LEConverter.UShortFrom(4, data);

			((AnalogValue)callbacks[TYPE_ANALOG_VALUE])(value);
			return 6;
		}

		public int CallbackCurrentReached(byte[] data)
		{
			short current = LEConverter.ShortFrom(4, data);

			((CurrentReached)callbacks[TYPE_CURRENT_REACHED])(current);
			return 6;
		}

		public int CallbackAnalogValueReached(byte[] data)
		{
			ushort value = LEConverter.UShortFrom(4, data);

			((AnalogValueReached)callbacks[TYPE_ANALOG_VALUE_REACHED])(value);
			return 6;
		}

		public int CallbackOverCurrent(byte[] data)
		{
			((OverCurrent)callbacks[TYPE_OVER_CURRENT])();
			return 4;
		}

		public void RegisterCallback(System.Delegate d)
		{
			if(d.GetType() == typeof(Current))
			{
				callbacks[TYPE_CURRENT] = d;
			}
			else if(d.GetType() == typeof(AnalogValue))
			{
				callbacks[TYPE_ANALOG_VALUE] = d;
			}
			else if(d.GetType() == typeof(CurrentReached))
			{
				callbacks[TYPE_CURRENT_REACHED] = d;
			}
			else if(d.GetType() == typeof(AnalogValueReached))
			{
				callbacks[TYPE_ANALOG_VALUE_REACHED] = d;
			}
			else if(d.GetType() == typeof(OverCurrent))
			{
				callbacks[TYPE_OVER_CURRENT] = d;
			}
		}
	}
}
