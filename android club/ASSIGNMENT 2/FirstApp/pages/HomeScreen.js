import * as React from 'react';
import {Button, View, Text, SafeAreaView} from 'react-native';

const HomeScreen = ({navigation}) => {
  
  return (
    <SafeAreaView style={{flex: 1}}>
      <View style={{flex: 1, padding: 16}}>
        <View
          style={{
            flex: 1,
            alignItems: 'center',
            justifyContent: 'center',
          }}>
          <Text
            style={{
              fontSize: 30,
              textAlign: 'center',
              marginBottom: 16,
            }}>
            WELCOME TO THE OFFICIAL APP OF NP_SOLUTIONS

          </Text>
          
          <Button
            onPress={() => navigation.navigate('ExploreScreen')}
            title="COMMITEE MEMBERS"
          />
        </View>
        <Text
          style={{
            fontSize: 18,
            textAlign: 'center',
            color: 'grey'
          }}>
          
        </Text>
        <Text
          style={{
            fontSize: 16,
            textAlign: 'center',
            color: 'grey'
          }}>
          
        </Text>
      </View>
    </SafeAreaView>
  );
};

export default HomeScreen;