import React from 'react';
import {StyleSheet, View, StatusBar, Button} from 'react-native';
import Tolly from './Tolly';

import { Text } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';

export default function AppTolly({ navigation }) {
  return (
    <View style={styles.container}>
      <StatusBar barStyle="light-content" backgroundColor="#030303" />
      <Tolly />
      <Button title="Go back" onPress={() => navigation.goBack()} />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#030303',
    // alignItems: 'center',
    justifyContent: 'center',
  },
});